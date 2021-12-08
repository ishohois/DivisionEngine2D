#include "GameManager.h"
#include "SystemResources.h"
#include "TestGameObject.h"
#include "Vector2D.h"

using namespace diva;

int main(int argc, char *argv[])
{
    std::cout << "Vectors v1(2, 5) and v2(2,2)\n";
    Vector2D v1(2, 5);
    Vector2D v2(2, 2);

    std::cout << "v2.magnitude: " << v2.magnitude() << std::endl;
    std::cout << "v1 = " << v1 << std::endl;
    std::cout << "v2 = " << v2 << std::endl;

    std::cout << "v4 is assigned the product cf v2 multiplied by 5\n";
    Vector2D v4 = v2 * 5;
    std::cout << "v5 is created by copyconstructing v2\n";
    Vector2D v5(v2);

    std::cout << "v5 is multiplied by 5\n";
    v5 *= 5;

    std::cout << "v2 = " << v2 << std::endl;
    std::cout << "v4 = " << v4 << std::endl;
    std::cout << "v5 = " << v5 << std::endl;

    std::cout << "subtract v2 from v1\n";
    v1 -= v2;

    std::cout << "v3 is assigned the difference of v1 and v2\n";
    Vector2D v3 = v1 - v2;
    std::cout << "v1 = " << v1 << std::endl;
    std::cout << "v2 = " << v2 << std::endl;
    std::cout << "v3 = " << v3 << std::endl;

    std::cout << "v6 is assigned the negative v5\n";
    Vector2D v6 = -v5;
    std::cout << "v6 = " << v6 << std::endl;

    std::cout << "v7 divided by 2\n";
    Vector2D v7 = v1 / 2;
    std::cout << "v7 = " << v7 << std::endl;

    std::cout << "v7 assigned v5\n";
    v7 = v5;
    std::cout << "v7 = " << v7 << std::endl;

    std::cout << "v7 assigndivided by 5\n";
    v7 /= 5;
    std::cout << "v7 = " << v7 << std::endl;
    
    std::cout << "v6 = " << v6 << std::endl;
    std::cout << "v6.magnitude " << v6.magnitude() << std::endl;

    v6.normalize();
    std::cout << "v6 = " << v6 << std::endl;

    std::cout <<"v6.magnitude after normalized operation\n"; 
    std::cout << v6.magnitude() << std::endl;

    return 0;
}
