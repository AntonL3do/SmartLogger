#include <map>

using namespace std;

class Registry{
public:
	Registry();
	~Registry();

	void registerKey(char key);
	map<int, int> getDB();
	void setDB(Registry *M);
	void setDB(char K, int V);
	void update(char K, int V);

private:
	map<int, int> db;
};