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


    // int* const 
    class ConstPractice9
    {
    private:
        int m_nValue;

    public:
        ConstPractice9() : m_nValue(0) {}

        int Practice(int* const practice)
        {
            // 상수 포인터 to int
            m_nValue += *practice;
            *practice = m_nValue;
//			practice = &m_nValue; // ❌ 컴파일 에러: const 포인터는 재할당 불가
            return m_nValue;
        }
    };

    // const int*
    class ConstPractice10
    {
    private:
        int m_nValue;

    public:
        ConstPractice10() : m_nValue(0) {}

		// int const* practice
        int Practice(const int* practice)
        {
            // 포인터 to 상수 int
            //m_nValue += practice;
            //x = m_nValue; // ❌ 컴파일 에러
            return m_nValue;
        }
    };

    // const int* const
    class ConstPractice11
    {
    private:
        int m_nValue;

    public:
        ConstPractice11() : m_nValue(0) {}

        // int const* practice
        int Practice(const int* const practice)
        {
            // 포인터 to 상수 int
            //m_nValue += practice;
            //x = m_nValue; // ❌ 컴파일 에러
            return m_nValue;
        }
    };

    // int& const
    class ConstPractice12
    {
    private:
        int m_nValue;

    public:
        ConstPractice12() : m_nValue(0) {}

        int Practice(const int& const practice)
        {
            m_nValue += practice;
            //x = m_nValue; // ❌ 컴파일 에러
            return m_nValue;
        }
    };

    // const int const
    class ConstPractice13
    {
    private:
        int m_nValue;

    public:
        ConstPractice13() : m_nValue(0) {}

        int Practice(const int const practice)
        {
            m_nValue += practice;
            //x = m_nValue; // ❌ 컴파일 에러
            return m_nValue;
        }
    };

    class People
    {
    private:
        int m_nAge;

    public:
		People() : m_nAge(100) {}
		People(int age) : m_nAge(age) {}

        void SetAge(int age)
        {
			m_nAge = age;
        }

        void SetAge(char* age)
        {
			m_nAge = atoi(age);
        }
    };
}

int main()
{
    std::cout << "Hello World!\n";

    dopple::ConstPractice1* p1 = nullptr;  

    dopple::ConstPractice1 value = dopple::ConstPractice1();
    dopple::ConstPractice1& p2 = value;

    //dopple::ConstPractice1& p2 = dopple::ConstPractice1();



#pragma region 힙_스택
    // 스택에 생성
    //dopple::ConstPractice1 p1 = dopple::ConstPractice1();
    //   p1.Practice(10);

    // 힙에 생성
    //dopple::ConstPractice1* p2 = new dopple::ConstPractice1();
    //p2->Practice(10);
#pragma endregion

#pragma region 포인터
    //int x = 10;
    //int* px = &x;
    //int px = &x;
    //int& rx = x;

    int* px = new int(100);
    int& r1 = *px;  // r: 스택에 있지만, *px는 힙의 데이터
//    int& r2 = px;  // r: 스택에 있지만, *px는 힙의 데이터


    //dopple::ConstPractice1 p2 = dopple::ConstPractice1();
    //dopple::ConstPractice1 p3 = new dopple::ConstPractice1();

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


    //dopple::People people;
    //people.SetAge(NULL);
    //people.SetAge(nullptr);

    //std::nullptr_t np = nullptr;

    std::cout << std::is_same<decltype(nullptr), std::nullptr_t>::value << std::endl;
#pragma endregion

#pragma region CONST

    int x = 10;
    int y = 20;
    int& r = x;

    r = y;      // x = y 와 동일, r은 여전히 x를 참조

    int tmp = 5;
    auto tmp2 = new int(5);
    auto tmp3 = new int(5);

    const int        practice1 = tmp;
    int const        practice2 = tmp;
    const int const  practice3 = tmp;

    const int&       practice4 = tmp;
    int& const       practice5 = tmp;
    const int& const practice6 = tmp;

    int* const       practice7 = tmp2;
    const int* const practice8 = tmp2;
    const int*       practice9 = tmp2;

    //practice1 = 100;
    //practice2 = 100;
    //practice3 = 100;

    //practice4 = 100;
    //practice5 = 100;
    //practice6 = 100;

    //*practice7 = 100;
    //*practice8 = 100;
    //*practice9 = 100;

    //*practice10 = 100;
    //*practice11 = 100;
    //*practice12 = 100;


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
