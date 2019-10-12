namespace Terry {
	_declspec(dllimport) void Print();
}
void main() {
	Terry::Print();
	while (true);
}