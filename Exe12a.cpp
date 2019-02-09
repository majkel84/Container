#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

void shuffleVector(std::vector<char> & v1, std::vector<char> & v2);
void emplaceVector(std::vector<char> & v);
void showVector(std::vector<char> & v);
void convertStringToVector(std::string & s, std::vector<char> & v3);
void enterSentence(std::string & s);
void showSentence(std::string & s);
void encrypting(std::vector<char> & v1, std::vector<char> & v2, std::vector<char> & v3);
void decrypting(std::vector<char> & v1, std::vector<char> & v2, std::vector<char> & v3);
void testEncryptingTable(std::vector<char> & v1, std::vector<char> & v2);

int main()
{    
    std::vector<char> vec1;
    std::vector<char> vec2;
    std::string sentence = {"Zdanie do zakodowanie, nie moze byc zbyt krotkie, i nie moze zawierac tez polskich znakow !@#$%^"};
    std::vector<char> vec3;

    emplaceVector(vec1);
    shuffleVector(vec1, vec2);
    //testEncryptingTable(vec1, vec2);
    convertStringToVector(sentence, vec3);
    encrypting(vec1, vec2, vec3);
    std::cout << "Encrypting ";
    showVector(vec3);
    decrypting(vec1, vec2, vec3);
    std::cout << "Decrypting ";
    showVector(vec3);

    std::cin.get();
    return 0;
}

void shuffleVector(std::vector<char> & v1, std::vector<char> & v2)
{
    v2 = v1;
    std::random_shuffle(v2.begin(),v2.end());
    std::rotate(v2.begin(), v2.begin() + rand() % 100, v2.end());
    std::next_permutation(v2.begin(), v2.end());
}

void emplaceVector(std::vector<char> & v)
{
    for (int i = 32; i<=126; i++)
        v.emplace_back(static_cast<char>(i)); 
    v.shrink_to_fit();
}

void showVector(std::vector<char> & v)
{
    for (const auto & i : v)
        std::cout << i;
    std::cout << '\n';
}

void enterSentence(std::string & s)
{
    std::cout << "Enter sentence: ";
    std::cin >> s;
}

void showSentence(std::string & s)
{
    std::cout << s;
}

void convertStringToVector(std::string & s, std::vector<char> & v3)
{
    std::copy(s.begin(), s.end(), std::back_inserter(v3));
}

void encrypting(std::vector<char> & v1, std::vector<char> & v2, std::vector<char> & v3)
{
    std::vector<char> v4;
    for (auto it3 = v3.begin(); it3 != v3.end(); it3++)
    {
        for (auto it1 = v1.begin(); it1 < v1.end(); it1++)
        {
            if (*it3 == * it1){
                v4.emplace_back(v2[it1-v1.begin()]);
            }
        }
    }
    v3.clear();
    v3 = v4;
}

void decrypting(std::vector<char> & v1, std::vector<char> & v2, std::vector<char> & v3)
{   
    std::vector<char> v4;
    for (auto it3 = v3.begin(); it3 != v3.end(); it3++)
    {
        for (auto it2 = v2.begin(); it2 < v2.end(); it2++)
        {
            if (*it3 == * it2){
                v4.emplace_back(v1[it2-v2.begin()]);
            }
        }
    }
    v3.clear();
    v3 = v4;
}


void testEncryptingTable(std::vector<char> & v1, std::vector<char> & v2)
{
    std::cout << "Vector 1" << '\n';
    std::cout << "Size: " << v1.size() << '\n';
    std::cout << "Capacity: " << v1.capacity() << '\n';
    std::cout << "Vector 2" << '\n';
    std::cout << "Size: " << v2.size() << '\n';
    std::cout << "Capacity: " << v2.capacity() << '\n';
    for(const auto & i : v1)
        std::cout << i << ":    " << v1[i] << ",    " << v2[i] << '\n';
}
