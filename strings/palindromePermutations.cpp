#include <string>
#include <assert.h>
using namespace std;

const static int arrSize = 256;//allow for ascii characters

bool palindPerm(string s) {
    int library[arrSize], countOdds = 0;
    for(int i = 0; i < arrSize; i++)//initialize array with 0s
        library[i] = 0;
    
    for(int i = 0; i < s.size(); i++) {
        library[tolower((int)s[i])]++; //use to lower to disregard differences in capitalization
    }
    for(int i = 0; i < arrSize; i++) {
        if (library[i] % 2) {
            countOdds++;
            if (countOdds > 1)
                return false;
        }
    }
    return true;
}

int main() {
    assert(!palindPerm("Wannablast"));
    assert(palindPerm("dammitimmad"));
    assert(palindPerm("starevilnonoevilstar"));
    assert(palindPerm("starevilnotnoevilstar"));
    assert(!palindPerm("pstarevilnotnoevilstar"));
    assert(palindPerm("&star evilno!!!no evilstar&"));
}
