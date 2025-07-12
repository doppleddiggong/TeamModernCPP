#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <unordered_map>

string solution(vector<string> participant, vector<string> completion)
{
    std::unordered_map<std::string, int> map;
    for (const auto& name : participant)
        map[name]++;

    for (const auto& name : completion)
    {
        if( map.find(name) != map.end() && 
            map[name] > 0)
        {
            map[name]--;

            if (map[name] == 0)
				map.erase(name);    
		}
    }

    return map.begin()->first;
}

int main(void) {

    std::cout << solution(vector<string> {"mislav", "stanko", "mislav", "ana"}, 
        vector<string>{"stanko", "ana", "mislav"});
}