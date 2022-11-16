#include "main.hpp"


int	main(void)
{
	std::string 				file;
	int							nb_serv;
	std::vector<int>			tab_len;
	std::vector<std::string>    servers;
	std::vector<s_parsing>		parsing;

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


	for (int i = 0; i < parsing.size(); i++)
	{
		std::map<std::string, std::string>::iterator it = parsing[i].error.begin();
		for (; it != parsing[i].error.end(); it++)
			std::cout << it->first << ' ' << it->second << std::endl;
	}

//	for (int i = 0; i < nb_serv; i++)
//		std::cout << parsing[i].size << std::endl;

//	for (int i = 0; i < nb_serv; i++)
//		std::cout << parsing[i].my_port << std::endl;

/*
	std::cout << nb_serv << std::endl;
	for (int i = 0; i < servers.size(); i++)
	{
		std::cout << "!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
		std::cout << servers[i] << std::endl;
	}
*/
}
