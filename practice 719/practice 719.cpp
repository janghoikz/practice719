#include <iostream>

using namespace std;

//생성자와 소멸자
// 이 중에서 굉장히 특별한 함수 2종이 있는데 바로 [시작]과 [끝]을 알리는 함수들
// - 시작(탄생) -> 생성자(여러개 존재가능)
// -  끝(소멸) -> 소멸자(오직1개만)

// 암시적 생성자
// 생성자를 명시적으로 만들지 않으면
// 아무 인자도 받지않는 기본생성자가 컴파일러에 의해 자동으로 만들어짐.
// 그러나 우리가 명시적으로 아무생성자 하나 만들면
// 자동으로 만들어지던 기본생성자는 더이상 만들어지지 않음

class Knight
{
public:
    //[1] 기본생성자(인자가 없음)
    Knight()
    {
        cout << "Knight() 기본 생성자 호출" << endl;

        mHp = 100;
        mAttack = 10;
        mPosX = 0;
        mPosY = 0;
    }

    // [2] 복사 생성자 (자기자신의 클래스 참조 타입을 인자로 받음)
    // 일반적으로 똑같은 데이터를 지닌 객체가 생성되길 기대한다
    Knight(const Knight& knight)
    {
        mHp = knight.mHp;
        mAttack = knight.mAttack;
        mPosX = knight.mPosX;
        mPosY = knight.mPosY;
    }

    // [3] 기타 생성자 
    Knight(int hp)
    {
        cout << "Knight(int) 생성자 호출" << endl;

        mHp = hp;
        mAttack = 10;
        mPosX = 0;
        mPosY = 0;
    }

    // 소멸자 
    ~Knight()
    {
        cout << "Knight () 기본 소멸자 호출" << endl;
    }

    //멤버 함수 선언
    void Move(int y, int x);
    void Attack();
    void Die()
    {
        mHp = 0;
        cout << "Die" << endl;
    }

public:
    //멤버 변수
    int mHp;
    int mAttack;
    int mPosY;
    int mPosX;
};

void Knight::Move(int y, int x)
{
    mPosY = y;
    mPosX = x;
    cout << "move" << endl;
}

void Knight::Attack()
{
    cout << "Attack : " << mAttack << endl;
}

int main()
{
    Knight k1(100);
    k1.mAttack = 10;
    k1.mPosY = 0;
    k1.mPosX = 0;

    Knight k2(k1);

    k1.Move(2, 2);
    k1.Attack();
    k1.Die();
}