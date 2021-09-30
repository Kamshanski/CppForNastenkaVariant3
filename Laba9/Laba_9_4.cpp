//
//  Смотри методичку. Там формулы
#include "../everything.h"

// Передача по ссылке
double rho(double& x, double& y, double& z) {
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

double fi(double& x, double& y) {
    return atan(y/x);
}

double zed(double& x, double& y, double& z) {
    return atan(sqrt(pow(x, 2) + pow(y, 2)) / z);
}




int main() {
    double x1 = 5, y1 = 2, z1 = 7;
    double x2 = 3, y2 = 4, z2 = 6;
    double rho1 = rho(x1,y1,z1);
    double rho2 = rho(x2,y2,z2);
    double zed1 = zed(x1,y1,z1);
    double zed2 = zed(x2,y2,z2);
    double fi1 = fi(x1,y1);
    double fi2 = fi(x2,y2);

    cout << "(" << x1 << ", " << y1 << ", " << z1 << ") -> "
         << "(" << rho1 << ", " << fi1 << ", " << zed1 << ")" << endl;

    cout << "(" << x2 << ", " << y2 << ", " << z2 << ") -> "
         << "(" << rho2 << ", " << fi2 << ", " << zed2 << ")" << endl;

    cout << "fi1 - fi2 = " << fi1 - fi2 << endl;
    cout << "rho1 - rho2 = " << rho1 - rho2 << endl;

    return 0;
}

