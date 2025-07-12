#include <iostream>
#include <windows.h>
#include <psapi.h>

// std::cout << "x = " << x << ", &x = " << &x << std::endl;
#define CLOG(var) std::cout << #var " = " << var << ", &" #var " = " << &(var) << std::endl;
// LOG("%d", 0);
#define LOG(fmt, ...) std::printf((fmt "\n"), ##__VA_ARGS__)

using namespace std;

namespace dopple
{
    void LogMemoryUsage(const char* tag)
    {
        PROCESS_MEMORY_COUNTERS pmc;
        if (GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc)))
        {
            SIZE_T workingSet = pmc.WorkingSetSize; // 현재 사용중인 메모리 (바이트)
            std::cout << tag << " - WorkingSetSize: " << workingSet << " Byte" << std::endl;
        }
    }

    class Practice
    {
    public:
        static int instance_count;
        static int create_count;

        Practice() {
            instance_count++;
            create_count++;
        }

        ~Practice() {
            instance_count--;
        }
    };

    int Practice::instance_count = 0;
    int Practice::create_count = 0;


    // 매개 변수가 int
    class ConstPractice1 : Practice
    {
    private:
        int m_nValue;

    public:
        ConstPractice1() : m_nValue(0) {
        };

        void Practice(int practice)
        {
            CLOG(practice);

            m_nValue += practice;
            practice = m_nValue;
        }
    };

    // 매개 변수가 int&
    class ConstPractice2
    {
    private:
        int m_nValue;

    public:
        ConstPractice2() : m_nValue(0) {}

        void Practice(int& practice)
        {
            CLOG(practice);

            m_nValue += practice;
            practice = m_nValue;
        }
    };

    // 매개 변수가 const int x
    class ConstPractice3
    {
    private:
        int m_nValue;

    public:
        ConstPractice3() : m_nValue(0) {}

        void Practice(const int practice)
        {
            CLOG(practice);

            m_nValue += practice;
            // practice = m_nValue; // ❌ 컴파일 에러: const 값에 할당 불가
        }
    };

    // 매개 변수가 const int& x
    class ConstPractice4
    {
    private:
        int m_nValue;

    public:
        ConstPractice4() : m_nValue(0) {}

        void Practice(const int& practice)
        {
            CLOG(practice);

            m_nValue += practice;
            // practice = m_nValue; // ❌ 컴파일 에러: const 참조에 할당 불가
        }
    };

    // 리턴이 const int 
    class ConstPractice5
    {
    private:
        int m_nValue;

    public:
        ConstPractice5() : m_nValue(0) {}

        const int Practice(const int& practice)
        {
            CLOG(practice);
            CLOG(m_nValue);

            m_nValue += practice;
            // practice = m_nValue; // ❌ 컴파일 에러
            return m_nValue;
        }
    };

    // 리턴이 const int&
    class ConstPractice6
    {
    private:
        int m_nValue;

    public:
		ConstPractice6() : m_nValue(0) {}

        const int& Practice(const int& practice)
        {
            CLOG(practice);
            CLOG(m_nValue);

            m_nValue += practice;
            // x = m_nValue; // ❌ 컴파일 에러
            return m_nValue;
        }
    };


    // const 함수
    class ConstPractice7
    {
    private:
        int m_nValue;

    public:
        ConstPractice7() : m_nValue(0) {}

        void Practice(const int& practice) const
        {
            //m_nValue += practice;
            // x = m_nValue; // ❌ 컴파일 에러
            //return m_nValue;
        }
    };

    // mutable 키워드
    class ConstPractice8
    {
    private:
        mutable int m_nValue;

    public:
        ConstPractice8() : m_nValue(0) {}

        void Practice(const int& practice) const
        {
            m_nValue += practice;
            //x = m_nValue; // ❌ 컴파일 에러
            //return m_nValue;
        }
    };


    class People
    {
    private:
        int m_nAge;

    public:
		People() : m_nAge(100) {}
		People(int age) : m_nAge(age) {}
    };
}

int main()
{
    std::cout << "Hello World!\n";

#pragma region 힙_스택
    // 스택에 생성
    //dopple::ConstPractice1 p1 = dopple::ConstPractice1();
    //   p1.Practice(10);

    // 힙에 생성
    //dopple::ConstPractice1* p2 = new dopple::ConstPractice1();
    //p2->Practice(10);
#pragma endregion

#pragma region 포인터
    //dopple::ConstPractice1* p2 = nullptr;   

    //if(p2 == nullptr)
    //{
    //    p2 = new dopple::ConstPractice1();

    //    for (int i = 0 ; i < 100; i++)
    //    {
    //        // std::unique_ptr<dopple::ConstPractice1> p3 = std::make_unique<dopple::ConstPractice1>();
    //        new dopple::ConstPractice1();

    //        if (i % 10 == 0)
    //        {
    //            char buffer[32];
    //            sprintf_s(buffer, sizeof(buffer), "%d", i);
    //            std::string s(buffer);

    //            dopple::LogMemoryUsage(s.c_str());
    //        }
    //    }
    //}

    //dopple::LogMemoryUsage("END");
    //
    //LOG("inst : %d, create : :%d", dopple::Practice::instance_count, dopple::Practice::create_count);
#pragma endregion

#pragma region NULLPTR
   /* std::nullptr_t np = nullptr;
    std::cout << static_cast<void*>(np) << std::endl;
    std::cout << NULL << std::endl;
    std::cout << 0 << std::endl;*/
#pragma endregion

#pragma region CONST
    // void Practice(int x)
    // void Practice(int& x)
    // void Practice(const int x)
    // void Practice(const int& x)
    // const int Practice(const int& x)
    // const int& Practice(const int& x)
    // void Practice(int x) const
    // mutable Keyword

    //dopple::ConstPractice1 practice = dopple::ConstPractice1();

    //int main = 100;
    //CLOG(main);

    //practice.Practice(10);
    //const int y = test.Practice(main);
    //y += 100;
    //CLOG(y);
#pragma endregion
}
