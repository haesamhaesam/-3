#include <iostream>
#include<vector>
#include <string>

using namespace std;


class Item
{
public:
	Item(string name, int price)
	{
		name_ = name;
		price_ = price;
	}   

	string Getname()
	{
		return name_;
	}

	int GetPrice()
	{
		return price_;
	}

private:
	string name_;
	int price_;

};


template <typename T>  
class Inventory        
{
public:
	Inventory()
	{
		 
	}
	


	vector<T> VItem;

	void Setcapacity(int capacity)
	{
		capacity_ = capacity;
		VItem.reserve(capacity_);
		
	}

	bool AddItem(const string& name, int price)
	{
		if (VItem.size() >= capacity_)
		{
			cout << "인벤토리가 가득 찼습니다!" << endl;
			cout << "더 이상 아이템을 추가할 수 없습니다!" << endl;

			return false;
		}

		T A(name, price);
		VItem.push_back(A);

		return true;
	
	}

	void PrintAllItems()
	{
		for (int i = 0; i < VItem.size(); i++)
		{
			cout << "아이템명 : " << VItem[i].Getname() << " / " << "아이템 가격 : " << VItem[i].GetPrice() << "   ";
		}

	}

	void RemoveLastItem()
	{
		VItem.pop_back();
	}

	int GetSize() const
	{
		return VItem.size();
	}

	int GetCapacity() const
	{
		return VItem.capacity();
	}


private:

	int capacity_ = 0;
};






int main(void)
{
	int select = -1;
	int capacity;
	int i = 0;
	string name;
	int price;

	Inventory<Item> h;

	cout << "인벤토리 용량을 입력해주세요(1 이상)" << endl;
	cin >> capacity;

	while (i < 1)
	{
		if (capacity > 0)
		{
			h.Setcapacity(capacity);
			++i;
		}
		else
		{
			cout << "0이하를 입력할 수 없습니다. 다시 입력해주세요." << endl;
		}
	}

	cout << "인벤토리 용량이 " << capacity << "로 설정되었습니다." << endl;

	cout << "진행 선택: 1. 모든 아이템 정보 출력 2. 아이템 제작 및 인벤토리 추가 3. 마지막으로 추가한 아이템 제거 " << endl;
	cout << "4. 현재 아이템 갯수 확인 5.현재 인벤토리 최대용량 확인 0. 게임 나가기 " << endl;
	
	

	i = 0;
	while (i == 0)
	{
		cout << "번호를 입력해주세요." << endl;
		cin >> select;

		if (select == 0)
		{
			cout << "프로그램을 종료합니다." << endl;
			++i;
			break;
		}



		switch (select)
		{

		case 1:
			cout << "모든 아이템 정보 출력" << endl;
			h.PrintAllItems();
			
			break;


		case 2:
			cout << "아이템 제작" << endl;
			{
				cout << "아이템 이름: " << endl;
				cin >> name;
				cout << "아이템 가격: " << endl;
				cin >> price;
				if (h.AddItem(name, price))
				{
					cout << name << "아이템이 추가되었습니다." << endl;
				}
			}
			
			break;

		case 3:
			cout << "마지막으로 추가된 아이템을 삭제합니다." << endl;
			h.RemoveLastItem();
			break;

		case 4:
			cout << "현재 아이템 갯수는 ";
			cout << h.GetSize() << "개 입니다." << endl;
			break;

		case 5:
			cout << "현재 인벤토리의 최대용량은 " << h.GetCapacity() << " 칸 입니다." << endl;
			
			break;
				

		default:
			cout << "잘못된 입력입니다." << endl;
			break;
		}

	}

	

	return 0;
}