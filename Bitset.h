#ifndef NULL
#define NULL 0
#endif // !NULL

// offset for byte
#ifndef __BYTEOFFSET
#define __BYTEOFFSET 8
#endif // !__BYTEOFFSET

// masks to extract bit k
#ifndef __BITMASKS
#define __BITMASKS

#define __SETBIT0MASK 0x01
#define __SETBIT1MASK 0x02
#define __SETBIT2MASK 0x04
#define __SETBIT3MASK 0x08
#define __SETBIT4MASK 0x10
#define __SETBIT5MASK 0x20
#define __SETBIT6MASK 0x40
#define __SETBIT7MASK 0x80

#define __RESETBIT0MASK ~__SETBIT0MASK
#define __RESETBIT1MASK ~__SETBIT1MASK
#define __RESETBIT2MASK ~__SETBIT2MASK
#define __RESETBIT3MASK ~__SETBIT3MASK
#define __RESETBIT4MASK ~__SETBIT4MASK
#define __RESETBIT5MASK ~__SETBIT5MASK
#define __RESETBIT6MASK ~__SETBIT6MASK
#define __RESETBIT7MASK ~__SETBIT7MASK

#endif // !__BITMASKS


#ifndef __BITSET_T

#define __BITSET_T

#include <string>

using namespace std;

class Bitset
{
private:
	int capacity;
	int size;
	int bitsPerRow;
	char * set;

	bool testBit(int i, int j);

	int countCharsInFile(string s_fileName);

	int bitsToBytes(int bits);

	void setBit(int i, int j, int val);

public:
	Bitset(char ** ca_matrix, int i_size); // square matrix of size size

	Bitset(int i_size); // size is the number of bits to store

	Bitset(string s_fileName, int size); // builds a bitset from the data in the file named s_fileName

	Bitset(Bitset &other);

	~Bitset(void);

	int operator()(int i, int j); // retrieves the bit located in the ith byte, at the offset j
	int operator[](int i); // retrieves the ith bit in the set

	int getBytes()
	{
		return capacity;
	}

	int getBits()
	{
		return size;
	}

	int getBitsPerRow()
	{
		return bitsPerRow;
	}

	bool allOnes(void);
	bool allZeroes(void);

	void setBit(int i, int val);
	void setBit(int i, int j, bool b_val);

	void resize(int i_size); // resizes the bitset to the new size

	void writeSetToFile(string s_fileName); // writes this bitset to the file named s_fileName

	friend ostream& operator<<(ostream&, Bitset*); // stream insertion operator for outputting bitset
}; // end Class Bitset
#endif // !__BITSET_T
