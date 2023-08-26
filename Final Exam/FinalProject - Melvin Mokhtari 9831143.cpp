//FinalProject - Melvin Mokhtari 9831143
#include <iostream>
#include <vector>

using namespace std;

class HorizontalBar
{
	private:
		int x1;
		int x2;
		int y;
	public:
		HorizontalBar(int x1, int x2, int y)
		{
			if ( x2 > x1)
			{
			this->x1 = x1;
			this->x2 = x2;
			this->y = y;
			}
			else
			{
				cout<<"Input Not Valid.";
			}
		}
		int get_x1()
		{
			return x1;
		}
		int get_x2()
		{
			return x2;
		}
		int get_y()
		{
			return y;
		}
};

class VerticalBar
{
	private:
		int x;
		int y1;
		int y2;
	public:
		VerticalBar(int y1, int y2, int x)
		{
			if ( y2 > y1)
			{
			this->y1 = y1;
			this->y2 = y2;
			this->x = x;
			}
			else
			{
				cout<<"Input Not Valid.";
			}
		}
		int get_y1()
		{
			return y1;
		}
		int get_y2()
		{
			return y2;
		}
		int get_x()
		{
			return x;
		}	
};

class Graph
{
	protected:
		int max_y;
		int max_x;	
};

class HorizontalGraph : public Graph
{
	private:
		vector<HorizontalBar> bars;
		void sort_bars()
		{
			int max_index;
			HorizontalBar bar(0,1,2);
			for(int i = bars.size() - 1 ; i >= 0 ; i--)
			{
				max_index = 0;
				for(int j = 0 ; i < i ; j++)
				{
					if ( bars[j].get_x1() > bars[max_index].get_x2() )
						max_index = j;
				}
				
				bar = bars[i];
				bars[i] = bars[max_index];
				bars[max_index] = bar;
			}
		}
	public:
		vector<HorizontalBar> get_bars()
		{
			return this->bars;
		}
		HorizontalGraph(int max_x, int max_y, vector<HorizontalBar> bars)
		{
			for(int i = 1; i < bars.size(); i++)
			{
				if ( bars[i].get_x1() < bars[i-1].get_x2() )
				{
					cout<<"Bars are not sorted.";
					return;
				}
			}
			this->sort_bars();
			this->max_x = max_x;
			this->max_y = max_y;
			this->bars = bars;
		}
		HorizontalGraph(int max_x, int max_y)
		{
			this->max_x = max_x;
			this->max_y = max_y;
		}
		void insert(vector<HorizontalBar> input_bars)
		{	
			bars.insert(bars.end(), input_bars.begin(), input_bars.end());
			this->sort_bars();
		}
		void remove(int begin, int end)
		{
			vector<HorizontalBar>::iterator it1 = bars.begin();
			vector<HorizontalBar>::iterator it2 = bars.begin();
			advance(it1, begin);
			advance(it2, end);
			bars.erase(it1, it2);
			this->sort_bars();
		}
		~HorizontalGraph()
		{
			bars.clear();
		}
		void operator + (HorizontalGraph graph)
		{
			this->insert(graph.bars);
			this->sort_bars();
			int size = bars.size();
			for(int i = 0; i < size ; i++)
			{
				if ( bars[i].get_x1() < bars[i + 1].get_x1() && bars[i].get_x2() < bars[i + 1].get_x2() )
				{
					bars[i] = HorizontalBar(bars[i].get_x1(),bars[i + 1].get_x2(), bars[i].get_y() + bars[i + 1].get_y());
					bars.erase( bars.begin() + i + 1);
					size--;
					i++;
				}
				else if ( bars[i].get_x1() > bars[i + 1].get_x1() && bars[i].get_x2() > bars[i + 1].get_x2() )
				{
					bars[i] = HorizontalBar(bars[i + 1].get_x1(), bars[i].get_x2(), bars[i].get_y() + bars[i + 1].get_y() );
					bars.erase( bars.begin() + i + 1);
					size--;
					i++;
				}
			}
		}
};

class VerticalGraph : public Graph
{
	private:		
		vector<VerticalBar> bars;		
		void sort_bars()
		{
			int max_index;
			VerticalBar bar(0,1,2);
			for(int i = bars.size() - 1 ; i >= 0 ; i--)
			{
				max_index = 0;
				for(int j = 0 ; i < i ; j++)
				{
					if ( bars[j].get_y1() > bars[max_index].get_y2() )
						max_index = j;
				}
				bar = bars[i];
				bars[i] = bars[max_index];
				bars[max_index] = bar;
			}
		}
	public:
		vector<VerticalBar> get_bars()
		{
			return this->bars;
		}
		VerticalGraph(int max_x, int max_y, vector<VerticalBar> bars)
		{
			for(int i = 1; i < bars.size(); i++)
			{
				if ( bars[i].get_y1() < bars[i-1].get_y2() )
				{
					cout<<"Bars are not sorted.";
					return;
				}
			}
			this->sort_bars();
			this->max_x = max_x;
			this->max_y = max_y;
			this->bars = bars;
		}
		VerticalGraph(int max_x, int max_y)
		{
			this->max_x = max_x;
			this->max_y = max_y;
		}		
		void insert(vector<VerticalBar> input_bars)
		{
			bars.insert(bars.end(), input_bars.begin(), input_bars.end());
			this->sort_bars();
		}
		void remove(int begin, int end)
		{
			vector<VerticalBar>::iterator it1 = bars.begin();
			vector<VerticalBar>::iterator it2 = bars.begin();
			advance(it1, begin);
			advance(it2, end);
			bars.erase(it1, it2);
			this->sort_bars();
		}
		~VerticalGraph()
		{
			bars.clear();
		}
		void operator + (VerticalGraph graph)
		{
			this->insert(graph.bars);
			this->sort_bars();
			int size = bars.size();
			for(int i = 0; i < size ; i++)
			{
				if ( bars[i].get_y1() < bars[i + 1].get_y1() && bars[i].get_y2() < bars[i + 1].get_y2() )
				{
					bars[i] = VerticalBar(bars[i].get_y1(),bars[i + 1].get_y2(), bars[i].get_x() + bars[i + 1].get_x());
					bars.erase( bars.begin() + i + 1);
					size--;
					i++;
				}
				else if ( bars[i].get_y1() > bars[i + 1].get_y1() && bars[i].get_y2() > bars[i + 1].get_y2() )
				{
					bars[i] = VerticalBar(bars[i + 1].get_y1(), bars[i].get_y2(), bars[i].get_x() + bars[i + 1].get_x() );
					bars.erase( bars.begin() + i + 1);
					size--;
					i++;
				}
			}
		}		
};

ostream& operator<<(ostream& os, VerticalGraph vg)
{
	for(int i = 0; i < vg.get_bars().size();i++)
	{
		os<<'('<<vg.get_bars()[i].get_x()<<",("<<vg.get_bars()[i].get_y1()<<','<<vg.get_bars()[i].get_y2()<<")\t,\t";
	}
	return os;
}
		
ostream& operator<<(ostream& os, HorizontalGraph hg)
{
	for(int i = 0; i < hg.get_bars().size();i++)
	{
		os<<"(("<<hg.get_bars()[i].get_x1()<<','<<hg.get_bars()[i].get_x2()<<"),"<<hg.get_bars()[i].get_y()<<")\t,\t";
	}
	return os;
}

int main()
{
	HorizontalGraph hg = HorizontalGraph(100,100);
	vector<HorizontalBar> bars;
	bars.push_back(HorizontalBar(6,9,15));
	bars.push_back(HorizontalBar(0,2,10));
	hg.insert(bars);
	cout<<hg;
	return 0;
}