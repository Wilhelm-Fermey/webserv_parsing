#include "main.hpp"

void number_server(std::vector<std::string> servers, std::vector<s_parsing> &parsing)
{
	int 	nb_loc;

	for (int i = 0; i < servers.size(); i++) // pour chaque server
	{
		int 						nb_loc = 0;
		std::string::size_type		pos = 0;
		std::vector<int> 			tab_len;
		std::vector<std::string>	tab_loc;
		std::string					target = "location";

		while ((pos = servers[i].find(target, pos )) != std::string::npos) // compte nb local + pos
		{
			nb_loc++;
			tab_len.push_back(pos);
			pos += target.length();
		}
		tab_len.push_back(servers[i].size());

		for (int j = 0; j < tab_len.size() -1; j++) // découpe les loc pour mettre dans tableau de loc
			tab_loc.push_back(servers[i].substr(tab_len[j], tab_len[j +1] - tab_len[j]));

		parsing[i].locations = tab_loc; 

		for (int j = 0; j < nb_loc; j++) // creation du bon nombre de struct location dans struct parsing.
			parsing[i].location.push_back(s_location());
	}
}

int	main(void)
{
	std::string 				file;
	int							nb_serv;
	std::vector<int>			tab_len; 
	std::vector<std::string>    servers; // .conf cut par server
	std::vector<s_parsing>		parsing; // info parsing

	/////////// SERVER ////////////
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

/*
	for (int i = 0; i < parsing.size(); i++)
	{
		std::map<std::string, std::string>::iterator it = parsing[i].error.begin();
		for (; it != parsing[i].error.end(); it++)
			std::cout << it->first << ' ' << it->second << std::endl;
	}
*/
	/////////// LOCATION ////////////

	number_server(servers, parsing);

}
