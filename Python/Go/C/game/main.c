#include "display.h"
#include "orgnise.h"

int main() {
    Member qwq = start();
    while(qwq.health > 0) {
        switch(choose()) {
        case 0:qwq = buy();break;
        case 1:qwq = qwq;break;
        case 2:qwq = qwq;break;
        default:qwq = qwq;break;
        }
    }
    return 0;
}