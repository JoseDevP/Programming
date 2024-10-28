#ifndef LCDE_H
#define LCDE_H
    #include "list.h"
    void error();

    Element *newElement();

    void initializeLcde(tlcse *lcde);

    int insert(void *e, tlcse *lcde);

    void *delete(tlcse *lcde);

    void goToNextOne(tlcse *lcse);

    void goToPreviousOne(tlcse *lcse);

    void goToBeginning(tlcse *lcse);

    void goToEnd(tlcse *lcse);

    int goToPosition(int i,tlcse *lcse);

    void *obtainCurrent(tlcse *lcse);

    void *obtain(int i, tlcse *lcse);

    void modify(void *e, tlcse *lcse);
#endif