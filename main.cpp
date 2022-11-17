#include "main.hpp"

int	main(void)
{
	std::string 				file;
	int							nb_serv;
	std::vector<int>			tab_len; 
	std::vector<std::string>    servers; // .conf cut par server
	std::vector<s_parsing>		parsing; // info parsing

	////////////////////////////////////////////////////////////////
	/////////////////////        SERVER       //////////////////////
	////////////////////////////////////////////////////////////////

	file = ft_read_file("file.conf");
	nb_serv = number_server(file, tab_len);
	cut_server(file, tab_len, servers);
	if (create_struct(parsing, nb_serv))
		return (1);
	find_ip(servers, parsing, nb_serv);
	find_port(servers, parsing, nb_serv);
	find_name(servers, parsing, nb_serv);
	find_size(servers, parsing, nb_serv);
	find_error(servers, parsing, nb_serv);

	/*..............................................................................*/
	/*.............. Loop to print info in parsing struct (string) .................*/
	/*..............................................................................*/

	for (int i = 0; i < parsing.size(); i++)
		std::cout << parsing[i].my_port <<std::endl;

	/*..............................................................................*/
	/*.............. Loop to print info in parsing struct (map) ....................*/
	/*..............................................................................*/
/*
	for (int i = 0; i < parsing.size(); i++)
	{
		std::map<std::string, std::string>::iterator it = parsing[i].error.begin();
		for (; it != parsing[i].error.end(); it++ )
			std::cout << it->first << ' ' << it->second << std::endl;
	}
*/

	////////////////////////////////////////////////////////////////
	//////////////////         LOCATION         ////////////////////
	////////////////////////////////////////////////////////////////

	number_server(servers, parsing);
	find_req_client(parsing);
	find_root(parsing);
	find_index(parsing);
	find_dir_listing(parsing);
	find_methods(parsing);
	find_redir(parsing);
	find_cgi(parsing);

	/*..............................................................................*/
	/*.............. Loop to print info in location struct (string) ................*/
	/*..............................................................................*/
/*
	for (int i = 0; i < parsing.size(); i++)
	{
		for (int j = 0; j < parsing[i].location.size(); j++)
			std::cout << parsing[i].location[j].req_client << std::endl;
	}
*/
	/*..............................................................................*/
	/*................ Loop to print info in location struct (map) .................*/
	/*..............................................................................*/

/*
	for (int i = 0; i < parsing.size(); i++)
	{
		for (int j = 0; j < parsing[i].location.size(); j++)
		{
			std::map<std::string, std::string>::iterator it = parsing[i].location[j].cgi.begin();
			for (; it != parsing[i].location[j].cgi.end(); it++ )
				std::cout << it->first << ' ' << it->second << std::endl;
		}
	}
*/
}
