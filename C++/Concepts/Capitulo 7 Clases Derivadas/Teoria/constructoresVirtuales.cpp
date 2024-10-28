#include <iostream>

class CB
{
    private:
        int i;
    public:
        CB() {std::cout << "constructor CB\n";}
        virtual ~CB() {std::cout << "destructor CB\n";}
        virtual CB* nuevo() { return new CB; }
        virtual CB* clonar() { return new CB(*this); }
};

class CD : public CB
{
    private:
        double j;
    public:
        CD() {std::cout << "constructor CD\n";}
        ~CD() override {std::cout << "destructor CD\n";}
        CD* nuevo() override { return new CD; }
        CD* clonar() override { return new CD(*this); }
};

CB* crearObjeto(CB* p)
{
    return p->nuevo();
}

int main()
{
    CB obj_cb, *cb = &obj_cb;
    CD obj_cd, *cd = &obj_cd;

    CB* p1_CB = crearObjeto(cb);
    CB* p2_CD = crearObjeto(cd);

    CB* p3_CB = p1_CB->clonar();
    CB* p4_CD = p2_CD->clonar();
    
    delete p1_CB;
    delete p2_CD;
    delete p3_CB;
    delete p4_CD;
    
}




