#include <stdio.h>

int main() {
    char light, pedestrian, cross;
    // 读取输入（注意空格问题，用getchar()跳过换行）
    light = getchar();
    getchar(); // 跳过第一行的换行符
    pedestrian = getchar();
    getchar(); // 跳过第二行的换行符
    cross = getchar();

    char result;
    if (light == 'R') {
        result = 'T';
    } else if (light == 'Y') {
        if (pedestrian == 'Y') {
            result = 'T';
        } else {
            result = (cross == 'P') ? 'G' : 'T';
        }
    } else if (light == 'G') {
        result = (pedestrian == 'N') ? 'G' : 'T';
    }

    printf("%c\n", result);
    return 0;
}