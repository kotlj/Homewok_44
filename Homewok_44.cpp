
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    while (b > 0)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

class drob
{
private:
    int numerator;
    int denomirator;

    void skorot()
    {
        int a = gcd(abs(numerator), denomirator);
        if (a != 1)
        {
            numerator /= a;
            denomirator /= a;
        }
    }
public:
    drob(int _numerator = 1, int _denomirator = 1)
    {
        if (denomirator != 0)
        {
            numerator = _numerator;
            denomirator = _denomirator;
        }
        else
        {
            numerator = _numerator;
            denomirator = 1;
        }
    }

    int getNumerator()
    {
        return numerator;
    }
    int getDenomirator()
    {
        return denomirator;
    }

    void show()
    {
        cout << numerator << "/" << denomirator;
    }

    drob operator * (drob b)
    {
        this->numerator *= b.numerator;
        this->denomirator *= b.denomirator;
        skorot();
        return *this;
    }
    drob operator / (drob b)
    {
        this->numerator *= b.denomirator;
        this->denomirator *= numerator;
        skorot();
        return *this;
    }
    drob operator - (drob b)
    {
        int unionDenom = lcm(this->denomirator, b.getDenomirator());
        if (this->denomirator != b.getDenomirator())
        {
            int relNumer = this->numerator * (unionDenom / this->denomirator);
            int mulNumer = b.getNumerator() * (unionDenom / b.denomirator);
            this->numerator = relNumer - mulNumer;
        }
        else
        {
            this->numerator -= b.getNumerator();
        }
        this->denomirator = unionDenom;
        skorot();
        return *this;
    }
    drob operator + (drob b)
    {
        int unionDenom = lcm(this->denomirator, b.getDenomirator());
        if (this->denomirator != b.getDenomirator())
        {
            int relNumer = this->numerator * (unionDenom / this->denomirator);
            int mulNumer = b.getNumerator() * (unionDenom / b.denomirator);
            this->numerator = relNumer + mulNumer;
        }
        else
        {
            this->numerator += b.getNumerator();
        }
        this->denomirator = unionDenom;
        skorot();
        return *this;
    }

};

int main()
{
    drob a(4, 6);
    drob b(2, 3);
    drob c = a - b;
    c.show();
}