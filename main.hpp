#ifndef MAIN_HPP
#define MAIN_HPP

# include <iostream>
# include <vector>
# include <map>
# include <fstream>

# include <string>
# include <algorithm>

struct s_parsing
{
    std::string							my_port; 
    std::string							my_ip;
    std::string							name_server;
	int									size;
	std::map<std::string, std::string> 	error;
};

//////////////////// PARSING_1 ///////////////////
std::string			ft_read_file(std::string file_path);
int 				number_server(std::string &file, std::vector<int> &tab_len);
void    			cut_server(std::string &file, std::vector<int> &tab_len,     std::vector<std::string> &servers);

//////////////////// PARSING_2 ///////////////////
int create_struct(std::vector<s_parsing> &parsing, int nb_serv);
void    find_ip(std::vector<std::string> servers, std::vector<s_parsing> &parsing, int nb_serv);
void    find_port(std::vector<std::string> servers, std::vector<s_parsing> &parsing, int nb_serv);
void    find_name(std::vector<std::string> servers, std::vector<s_parsing> &parsing, int nb_serv);
void    find_size(std::vector<std::string> servers, std::vector<s_parsing> &parsing, int nb_serv);
void    find_error(std::vector<std::string> servers, std::vector<s_parsing> &parsing, int nb_serv);

#endif
