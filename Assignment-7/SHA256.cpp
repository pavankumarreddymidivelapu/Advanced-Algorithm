#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <filesystem> 
#include <vector>
using namespace std;

#define ROTATE_RIGHT(x, n) ((x >> n) | (x << (32 - n)))

#define CHOOSE(x, y, z) ((x & y) ^ (~x & z))
#define MAJORITY(x, y, z) ((x & y) ^ (x & z) ^ (y & z))
#define SIGMA0(x) (ROTATE_RIGHT(x, 2) ^ ROTATE_RIGHT(x, 13) ^ ROTATE_RIGHT(x, 22))
#define SIGMA1(x) (ROTATE_RIGHT(x, 6) ^ ROTATE_RIGHT(x, 11) ^ ROTATE_RIGHT(x, 25))   
#define sigma0(x) (ROTATE_RIGHT(x, 7) ^ ROTATE_RIGHT(x, 18) ^ (x >> 3))
#define sigma1(x) (ROTATE_RIGHT(x, 17) ^ ROTATE_RIGHT(x, 19) ^ (x >> 10))

class SHA256 {
public:
    string hash(const string& message);

private:
    static const uint32_t CONSTANTS[64];
    uint32_t hashValues[8];
    string getResult();
    void processBlock(const vector<uint8_t>& block);
};

const uint32_t SHA256::CONSTANTS[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
        0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
        0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,     
        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
        0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
        0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
        0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
        0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
        0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
        0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2,
};

string SHA256::hash(const string& message) {
    hashValues[0] = 0x6a09e667;
    hashValues[1] = 0xbb67ae85;
    hashValues[2] = 0x3c6ef372;
    hashValues[3] = 0xa54ff53a;
    hashValues[4] = 0x510e527f;
    hashValues[5] = 0x9b05688c;
    hashValues[6] = 0x1f83d9ab;
    hashValues[7] = 0x5be0cd19;

    vector<uint8_t> paddedMsg(message.begin(), message.end());
    paddedMsg.push_back(0x80);

    size_t originalMsgLength = message.length() * 8;
    while ((paddedMsg.size() * 8) % 512 != 448)                
    {
        paddedMsg.push_back(0x00);
    }

    for (int i = 0; i < 8; ++i) {
        paddedMsg.push_back((originalMsgLength >> (56 - 8 * i)) & 0xFF);
    }

    for (size_t i = 0; i < paddedMsg.size(); i += 64) {
        processBlock(std::vector<uint8_t>(paddedMsg.begin() + i, paddedMsg.begin() + i + 64));
    }

    return getResult();
}

void SHA256::processBlock(const vector<uint8_t>& block) {
    vector<uint32_t> words(64, 0);      
    for (size_t i = 0; i < 16; ++i) {
        words[i] = (block[i * 4] << 24) | (block[i * 4 + 1] << 16) | (block[i * 4 + 2] << 8) | block[i * 4 + 3];
    }

    for (size_t i = 16; i < 64; ++i) {
        words[i] = sigma1(words[i - 2]) + words[i - 7] + sigma0(words[i - 15]) + words[i - 16];
    }

    uint32_t a = hashValues[0];
    uint32_t b = hashValues[1];
    uint32_t c = hashValues[2];
    uint32_t d = hashValues[3];
    uint32_t e = hashValues[4];
    uint32_t f = hashValues[5];
    uint32_t g = hashValues[6];
    uint32_t h = hashValues[7];

    for (size_t i = 0; i < 64; ++i) {
        uint32_t temp1 = h + SIGMA1(e) + CHOOSE(e, f, g) + CONSTANTS[i] + words[i];
        uint32_t temp2 = SIGMA0(a) + MAJORITY(a, b, c);
        h = g;
        g = f;
        f = e;
        e = d + temp1;
        d = c;
        c = b;
        b = a;
        a = temp1 + temp2;
    }

    hashValues[0] += a;
    hashValues[1] += b;
    hashValues[2] += c;
    hashValues[3] += d;
    hashValues[4] += e;
    hashValues[5] += f;
    hashValues[6] += g;
    hashValues[7] += h;
}

string SHA256::getResult() {
    stringstream ss;
    for (int i = 0; i < 8; ++i) {
        ss << hex << setfill('0') << setw(8) << hashValues[i];
    }
    return ss.str();
}

int main() {
    SHA256 sha256;

    cout << "Enter the text message to convert hashvalue: ";

    // Read the complete input from stdin
    istreambuf_iterator<char> begin(cin), end;
    string message(begin, end);

    string hashResult = sha256.hash(message);

    cout << "\nHash value after hasing: " << hashResult << endl;

    return 0;
}
