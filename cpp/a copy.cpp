#include <iostream>
using namespace std;

int main() {
    unsigned char cipher[] =
        {
            198, 44, 113, 215, 43, 231, 181, 44, 147, 95, 61, 181, 79, 180, 95, 79, 180, 232, 181, 79, 46,
            95, 231, 147, 95, 164, 181, 146, 79, 65, 63, 82, 116, 77, 0};
    int length = sizeof(cipher) / sizeof(cipher[0]);

    // 初步猜测的 flag 模板
    unsigned char flag[] = "flag{Wcllcome_to_the_Nowcode4gO24}";

    // 遍历每个字符，检查并匹配密文
    for (int i = 0; i < length; i++) {
        if (cipher[i] != 0) {
            // 检查当前字符是否匹配
            if ((flag[i] * 17) % 256 != cipher[i]) {
                bool found = false;
                cout << (int)flag[i] << endl;
                // 尝试从 32 到 126 的 ASCII 字符找到匹配的字符
                for (unsigned char c = 0; c <= 256; c++) {
                    if ((c * 17) % 256 == cipher[i]) {
                        flag[i] = c;
                        found = true;
                        break;
                    }
                }
                cout << (int)flag[i] << endl;
                if (!found) {
                    cout << "Failed to find a match for position " << i << endl;
                }
            }
        } else {
            break;
        }
    }

    // 输出解密后的 flag
    cout << "Decrypted flag: " << flag << endl;
    getchar();
    return 0;
}
