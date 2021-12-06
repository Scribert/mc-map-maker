import struct
import gzip

class NBT:
    def __init__(self, name, value):
        self.name = name
        self._data = value
    def data(self):
        return self._data
    def setValue(self, value):
        self._data = value
    def _generateTagName(self):
        return struct.pack('B', self.type) + struct.pack('>H', len(self.name)) + self.name.encode('utf-8')

class NBT_Byte(NBT):
    def __init__(self, name, value):
        super().__init__(name, value)
        self.type = 1
    def generateTag(self):
        return self._generateTagName() + struct.pack('b', self._data)

class NBT_Short(NBT):
    def __init__(self, name, value):
        super().__init__(name, value)
        self.type = 2
    def generateTag(self):
        return self._generateTagName() + struct.pack('>h', self._data)

class NBT_Int(NBT):
    def __init__(self, name, value):
        super().__init__(name, value)
        self.type = 3
    def generateTag(self):
        return self._generateTagName() + struct.pack('>i', self._data)

class NBT_Long(NBT):
    def __init__(self, name, value):
        super().__init__(name, value)
        self.type = 4
    def generateTag(self):
        return self._generateTagName() + struct.pack('>q', self._data)

class NBT_Float(NBT):
    def __init__(self, name, value):
        super().__init__(name, value)
        self.type = 5
    def generateTag(self):
        return self._generateTagName() + struct.pack('>f', self._data)

class NBT_Double(NBT):
    def __init__(self, name, value):
        super().__init__(name, value)
        self.type = 6
    def generateTag(self):
        return self._generateTagName() + struct.pack('>d', self._data)

class NBT_String(NBT):
    def __init__(self, name, value):
        super().__init__(name, value)
        self.type = 8
    def generateTag(self):
        return self._generateTagName() + struct.pack('>H', len(self._data)) + self._data.encode('utf-8')

class NBT_Compound(NBT):
    def __init__(self, name, value):
        super().__init__(name, value)
        self.type = 10
    def generateTag(self):
        output = self._generateTagName()
        for i in self._data:
            output += i.generateTag()
        return output + struct.pack('b', 0)

def generateNBT(data):
    output = NBT_Compound("", [data])
    return output.generateTag()

def saveFile(fileName, NBT, compress=True):
    if compress:
        file = gzip.open(fileName, 'wb')
        file.write(NBT)
        file.close()
    else:
        file = open(fileName, 'wb')
        file.write(NBT)
        file.close()

test = NBT_Compound("Hello", [NBT_String("myString", "hi hi hi"), NBT_Float("whasup", 3.14159), NBT_Byte("True", 1), NBT_Int("Thirty-Two", 32)])
testNBT = generateNBT(test)
saveFile("test.dat", testNBT)
