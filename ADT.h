#ifndef ADT_h
#define ADT_h

#include <iostream>

class ADT
{
    //
    public:
        virtual ~ADT() = default;
        virtual std::ostream &print(std::ostream &out) const { return out; }
        friend std::ostream &operator<<(std::ostream& out, const ADT& right)
        {
            return right.print(out);
        }

};

#endif // ADT_h

