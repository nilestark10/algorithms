#include<iostream>
using namespace std;

class Check {
	int val;
public:
	Check(): val(0){}
	void setValue(int newVal){
		this->val = newVal;
	}
	int getVal() {
		return this->val;
	}
};

struct TF : public testing::Test {
	Check* c1;
	void SetUp() {
		c1 = new Check();
	}
	void TearDown() {
		delete c1;
	}
};


TEST(TESTNAME, SubTestName) {
	//Arrange
	Check* c1 = new Check();

	//Act
	c1 = setVAlue(100);

	//Assert
	ASSET_EQ(c1)
}