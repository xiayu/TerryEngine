#include "Terry.h"
class SanBox :public Terry::Application
{
public:
	SanBox() {

	}

	~SanBox() {

	}

};
Terry::Application *Terry::CreateApplication() {
	return new SanBox();
}