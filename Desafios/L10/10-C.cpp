#include <iostream>

int main()
{
    int T, x, y, x1, y1, x2, y2, i, j, M;
    std::cin >> T;
    
    for (i = 1; i <= T; i++) {
        std::cin >> x1 >> y1 >> x2 >> y2;
        std::cin >> M;
        
        std::cout << "Case " << i << ":" << std::endl;
        
        for (j = 1; j <= M; j++) {
            std::cin >> x >> y;
            
            if (x > x1 && y > y1 && x < x2 && y < y2) {
                std::cout << "Yes" << std::endl;
            }
            else {
                std::cout << "No" << std::endl;
            }
        }
    }
    
    return 0;
}
