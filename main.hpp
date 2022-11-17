#ifndef MAIN_HPP
#define MAIN_HPP

# include <iostream>
# include <vector>
# include <map>
# include <fstream>
# include <string>
# include <algorithm>

//////////////////// STRUCTURE POUR CHAQUE LOCATION ////////////
struct s_location
{
	std::string							req_client;
    std::string							root; 
    std::string							path_index;
	std::string							dir_listing;
    std::string							methods;
	std::map<std::string, std::string> 	redir;
	std::map<std::string, std::string> 	cgi;

};

//////////////////// STRUCTURE PRINCIPALE //////////////////////
struct s_parsing
{
    std::string							my_port; 
    std::string							my_ip;
    std::string							name_server;
	int									size;
	std::map<std::string, std::string> 	error;
	std::vector<s_location>      		location;

	std::vector<std::string>      		locations; // aide pour parsing (ne pas utiliser).
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

//////////////////// PARSING_3 ///////////////////
void number_server(std::vector<std::string> servers, std::vector<s_parsing> &parsing);
void    find_req_client(std::vector<s_parsing> &parsing);
void    find_root(std::vector<s_parsing> &parsing);
void    find_index(std::vector<s_parsing> &parsing);
void    find_dir_listing(std::vector<s_parsing> &parsing);
void    find_methods(std::vector<s_parsing> &parsing);
void    find_redir(std::vector<s_parsing> &parsing);
void    find_cgi(std::vector<s_parsing> &parsing);

#endif
