class Array
{
private:
	int size;
	int expandStep;
	int* data;
	int curr;
public:
	Array();
	Array(int size, int expandStep);
	~Array();
	void showElements() const;
	void expandArray(int size);
	int getSize() const;
	int getElemSize() const;
	void setValue(int value);
	void setArray(int* arr, int arrSize);
};
