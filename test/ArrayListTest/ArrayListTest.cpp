#define BOOST_TEST_MODULE ArrayListTest module ArrayList
#include <boost/test/included/unit_test.hpp>
extern "C" {
#include "../../src/ex-2-ArrayList/ArrayList.h"
}


BOOST_AUTO_TEST_CASE(ArrayList_WhenGettingToAnItemAtIndex_EnsureItGotTheRightItem)
{
    const int VALUE_WE_WANT_TO_GET = 3;
    const size_t VALUE_INDEX = 0;
    ArrayList list;
    int resualt;
    bool functionRet;
    InitializeArrayList(&list, 5);
    AddItemToTheEndOfArrayList(&list, VALUE_WE_WANT_TO_GET);
    functionRet = TryGetItemAtIndexFromArrayList(&list, VALUE_INDEX, &resualt);
    DestructArrayList(&list);
    BOOST_CHECK(functionRet && resualt == VALUE_WE_WANT_TO_GET);
}