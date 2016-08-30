#include <string>
#include <iostream>
using namespace std;
class Solution {
   public:
    int lengthLongestPath(string input) {
        input += '\n';
        int pathPartLength[100];
        int tab = 0;
        bool append = false;
        bool isFile = false;
        int maxLength = 0;
        for (string::iterator it = input.begin(); it != input.end(); ++it) {
            switch (*it) {
                case '\n': {
                    if (isFile) {
                        int curLength = 0;
                        for (int i = 0; i <= tab; ++i) {
                            curLength += pathPartLength[i];
                        }
                        curLength += tab;
                        if (curLength > maxLength) {
                            maxLength = curLength;
                        }
                    }
                    tab = 0;
                    append = false;
                    isFile = false;
                    break;
                }
                case '\t': {
                    tab += 1;
                    break;
                }
                case '.': {
                    isFile = true;
                }
                default: {
                    if (!append) {
                        pathPartLength[tab] = 0;
                        append = true;
                    }
                    pathPartLength[tab] += 1;
                }
            }
        }
        return maxLength;
    }
};

int main() {
    string input = string(
        "dir\n\tsubdir1\n\t\tfile1."
        "ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext");
    cout << Solution().lengthLongestPath(input) << endl;
}
