#include "math_lib.h"
#include <cmath>
#include <algorithm>

namespace MathLib
{
    bool isEqual(double a, double b, double tolerance)
    {
        return abs(a - b) <= tolerance;
    }

    bool isPrime(int n)
    {
        if (n <= 1)
            return false;
        
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return false;        
        }
        return true;
    }

    int leastCommonMultiple(int a, int b)
    {
        int lcm = 1;
        int maxNum = std::max(a, b);
        for (int i = maxNum; i <= a * b; i += maxNum)
        {
            if (i % a == 0 && i % b == 0)
            {
                lcm = i;
                break;
            }
        }
        return lcm;
    }

    int GCD(int a, int b)
    {
		if (b == 0) return a;
		return GCD(b, a % b);
	}

    std::vector<double> solveQuadratic(double a, double b, double c)
    {
        if (isEqual(a, 0.0))
        {
            if (isEqual(b, 0.0))
            {
                if (isEqual(c, 0.0))
                {
                    throw std::invalid_argument("Infinite number of solutions (0 == 0).");
                }
                return {};
            }
            return { -c / b };
        }
        double discriminant = (b * b) - (4.0 * a * c);
        if (isEqual(discriminant, 0.0))
        {
            return { -b / (2.0 * a) };
        }
        else if (discriminant < 0.0)
        {
            return {};
        }
        else
        {
            double sqrtD = MathLib::sqrt(discriminant);
            double x1 = (-b - sqrtD) / (2.0 * a);
            double x2 = (-b + sqrtD) / (2.0 * a);
            return { x1, x2 };
        }
    }
}
