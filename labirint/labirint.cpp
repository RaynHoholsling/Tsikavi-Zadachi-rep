#include <iostream>
#include <vector>
#include <set>
using field = std::vector<std::vector<char>>;
using row = std::vector<char>;
using point = std::pair<int, int>;
using set_of_points = std::set<point>;

std::ostream& operator<<(std::ostream& out, field& lab);
std::istream& operator>>(std::istream& in, field& lab);
bool is_path_exist(const field& lab, const point& current, set_of_points& visited);
char get_value(const field& lab, const point& c);
std::vector<point> neighbours (const field& lab, const point& current);

const char coridor = ' ';
const char wall = 'X';
const char start = 'A';
const char stop = 'B';

int main()
{
	try
	{
		field labirint;
		std::cin >> labirint;
		std::cout << labirint << std::endl;
		std::cout << 
			(is_path_exist(labirint, )	
			 )
		       	<< std::endl
		return 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
}

point find_point(const field& labirint, char char_valid)
{
	for(int i = 0; i < labirint.size(); i++){
		for(int j = 0; j < labirint[0])
	}
}

std::vector<point> neighbours (const field& lab, const point& current)
{
	row current_row;
	std::vector<point> result;
	if(current.first > 0)
		result.push_back({current.first - 1, current.second});
	if(current.second > 0)
		result.push_back({current.first, current.second - 1});
	if(current.first < lab.size())
		result.push_back({current.first + 1, current.second});
	if(current.second < current_row.size())
		result.push_back({current.first, current.second + 1});

	return std::move(result);

}

bool is_path_exist(const field& lab, const point& current, set_of_points& visited)
{
	if (get_value(lab, current) == wall)
		return false;
	if (visited.count(current) > 0)
		return false;
	visited.insert(current);
	if (get_value(lab, current) == stop)
		return true;
	for(auto& neighbour: neighbours(lab, current))
	{
		if (is_path_exist(lab, current, visited))
			return true;
	}
	return false;
}

char get_value(const field& lab, const point& c)
{
	return lab[c.first][c.second];
}

std::ostream& operator<<(std::ostream& out, field& lab)
{
	for(auto i = lab.begin(); i != lab.end(); i++)
	{
		for(auto j = i->begin(); j != i->end(); j++)
			out << *j;
		out << std::endl;
	}
	return out;
}

std::istream& operator>>(std::istream& in, field& lab)
{
	char ch;
	row current_row;
	int row_index = 0;	
	int width = 0;
	bool met_A = false, met_B = false;
	while(in.get(ch))
	{
		if(ch == '\n')
		{
			if (current_row.size() == 0)
				break;
			if (row_index == 0)
				width = current_row.size();
			if (current_row.size() > 0 && current_row.size() != width)
				throw std::runtime_error("Invalid width of line: "
						+ std::to_string(row_index + 1));
                        lab.push_back(current_row);
                        current_row.clear();
			row_index++;
                }
		else if(ch == coridor || ch == start || ch == wall || ch == stop)
		{
			if (ch == start)
			{
				if (met_A)
					throw std::runtime_error (
						"Duplicated A "
						"at line: " 
						+ std::to_string(row_index + 1));
				met_A = true;
			}
			if (ch == stop)
			{
				if (met_B)
					throw std::runtime_error (
                                                "Duplicated B "
                                                "at line: "
                                                + std::to_string(row_index + 1));
				met_B = true;
			}
			current_row.push_back(ch);
			
		}
		else
		{
			throw std::runtime_error(
				"Invalid character at line: "
				+ std::to_string(row_index + 1)
				+ " column: "
				+ std::to_string(current_row.size() + 1));
		}
	}
	return in;
}
