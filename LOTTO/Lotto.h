class Lotto 
{
private:
	int m_cnt = 0;
	int m_array[7] = { 0 };
	int m_show_array[10][7] = { 0 };
	int m_countTable[46] = { 0 };
public:
	void draw();
	void show(int n);
	void stat();
};
