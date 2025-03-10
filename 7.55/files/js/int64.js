function Int64(low, high) {
    var bytes = new Uint8Array(8);
    if (arguments.length > 2 || arguments.length == 0)
        throw TypeError("Incorrect number of arguments to constructor");
    if (arguments.length == 2) {
        if (typeof low != 'number' || typeof high != 'number') {
            throw TypeError("Both arguments must be numbers");
        }
        if (low > 0xffffffff || high > 0xffffffff || low < 0 || high < 0) {
            throw RangeError("Both arguments must fit inside a uint32");
        }
        low = low.toString(16);
        for (let i = 0; i < 8 - low.length; i++) {
            low = "0" + low;
        }
        low = "0x" + high.toString(16) + low;
    }
    switch (typeof low) {
        case 'number':
            low = '0x' + Math.floor(low).toString(16);
        case 'string':
            if (low.substr(0, 2) === "0x")
                low = low.substr(2);
            if (low.length % 2 == 1)
                low = '0' + low;
            var bigEndian = unhexlify(low, 8);
            var arr = [];
            for (var i = 0; i < bigEndian.length; i++) {
                arr[i] = bigEndian[i];
            }
            bytes.set(arr.reverse());
            break;
        case 'object':
            if (low instanceof Int64) {
                bytes.set(low.bytes());
            } else {
                if (low.length != 8)
                    throw TypeError("Array must have excactly 8 elements.");
                bytes.set(low);
            }
            break;
        case 'undefined':
            break;
    }
    this.asDouble = function () {
        if (bytes[7] == 0xff && (bytes[6] == 0xff || bytes[6] == 0xfe))
            throw new RangeError("Can not be represented by a double");
        return Struct.unpack(Struct.float64, bytes);
    };
    this.asInteger = function () {
        if (bytes[7] != 0 || bytes[6] > 0x20) {
            debug_log("SOMETHING BAD HAS HAPPENED!!!");
            throw new RangeError(
                "Can not be represented as a regular number");
        }
        return Struct.unpack(Struct.int64, bytes);
    };
    this.asJSValue = function () {
        if ((bytes[7] == 0 && bytes[6] == 0) || (bytes[7] == 0xff && bytes[
            6] == 0xff))
            throw new RangeError(
                "Can not be represented by a JSValue");
        return Struct.unpack(Struct.float64, this.sub(0x1000000000000).bytes());
    };
    this.bytes = function () {
        var arr = [];
        for (var i = 0; i < bytes.length; i++) {
            arr.push(bytes[i])
        }
        return arr;
    };
    this.byteAt = function (i) {
        return bytes[i];
    };
    this.toString = function () {
        var arr = [];
        for (var i = 0; i < bytes.length; i++) {
            arr.push(bytes[i])
        }
        return '0x' + hexlify(arr.reverse());
    };
    this.low32 = function () {
        return new Uint32Array(bytes.buffer)[0] >>> 0;
    };
    this.hi32 = function () {
        return new Uint32Array(bytes.buffer)[1] >>> 0;
    };
    this.equals = function (other) {
        if (!(other instanceof Int64)) {
            other = new Int64(other);
        }
        for (var i = 0; i < 8; i++) {
            if (bytes[i] != other.byteAt(i))
                return false;
        }
        return true;
    };
    this.greater = function (other) {
        if (!(other instanceof Int64)) {
            other = new Int64(other);
        }
        if (this.hi32() > other.hi32())
            return true;
        else if (this.hi32() === other.hi32()) {
            if (this.low32() > other.low32())
                return true;
        }
        return false;
    };
    function operation(f, nargs) {
        return function () {
            if (arguments.length != nargs)
                throw Error("Not enough arguments for function " + f.name);
            var new_args = [];
            for (var i = 0; i < arguments.length; i++) {
                if (!(arguments[i] instanceof Int64)) {
                    new_args[i] = new Int64(arguments[i]);
                } else {
                    new_args[i] = arguments[i];
                }
            }
            return f.apply(this, new_args);
        };
    }
    this.neg = operation(function neg() {
        var ret = [];
        for (var i = 0; i < 8; i++)
            ret[i] = ~this.byteAt(i);
        return new Int64(ret).add(Int64.One);
    }, 0);
    this.add = operation(function add(a) {
        var ret = [];
        var carry = 0;
        for (var i = 0; i < 8; i++) {
            var cur = this.byteAt(i) + a.byteAt(i) + carry;
            carry = cur > 0xff | 0;
            ret[i] = cur;
        }
        return new Int64(ret);
    }, 1);
    this.assignAdd = operation(function assignAdd(a) {
        var carry = 0;
        for (var i = 0; i < 8; i++) {
            var cur = this.byteAt(i) + a.byteAt(i) + carry;
            carry = cur > 0xff | 0;
            bytes[i] = cur;
        }
        return this;
    }, 1);
   this.sub = operation(function sub(a) {
        var ret = [];
        var carry = 0;
        for (var i = 0; i < 8; i++) {
            var cur = this.byteAt(i) - a.byteAt(i) - carry;
            carry = cur < 0 | 0;
            ret[i] = cur;
        }
        return new Int64(ret);
    }, 1);
}
Int64.fromDouble = function (d) {
    var bytes = Struct.pack(Struct.float64, d);
    return new Int64(bytes);
};
Int64.Zero = new Int64(0);
Int64.One = new Int64(1);
Int64.NegativeOne = new Int64(0xffffffff, 0xffffffff);
