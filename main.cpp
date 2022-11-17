#include "main.hpp"
/*
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

void	find_req_client(std::vector<s_parsing> &parsing)
{
	for (int i = 0; i < parsing.size(); i++)
	{
		for (int j = 0; j < parsing[i].location.size(); j++)
		{
			int				start = 0;
			int				end = 0;
			std::string		target = "location";
			std::string		res;

			start = parsing[i].locations[j].find(target, start); //trouve target
			start = start + target.length(); // avance la taille de target
			while (parsing[i].locations[j][start] == ' ' or parsing[i].locations[j][start] == '	')
				start++; // avance
			end = start;
			while (parsing[i].locations[j][end] != ';' && parsing[i].locations[j][end] != ' ')
				end++; // avance juqu'a la fin de res
			res = parsing[i].locations[j].substr(start, end - start); // prend res
			parsing[i].name_server = res; // met res dans la struct
			parsing[i].location[j].req_client = res;
		}
	}
}

void	find_root(std::vector<s_parsing> &parsing)
{
	for (int i = 0; i < parsing.size(); i++)
	{
		for (int j = 0; j < parsing[i].location.size(); j++)
		{
			int				start = 0;
			int				end = 0;
			std::string		target = "root";
			std::string		res;

			while ((start = parsing[i].locations[j].find(target, start)) != std::string::npos)
			{
				start = start + target.length(); // avance la taille de target
				while (parsing[i].locations[j][start] == '	' or parsing[i].locations[j][start] == ' ')
					start++; // avance
				end = start;
				while (parsing[i].locations[j][end] != ';' && parsing[i].locations[j][end] != ' ')
					end++; // avance juqu'a la fin de res
				res = parsing[i].locations[j].substr(start, end - start); // prend res
				parsing[i].location[j].root = res;
			}
		}
	}
}

void	find_index(std::vector<s_parsing> &parsing)
{
	for (int i = 0; i < parsing.size(); i++)
	{
		for (int j = 0; j < parsing[i].location.size(); j++)
		{
			int				start = 0;
			int				end = 0;
			std::string		target = "index";
			std::string		res;

			while ((start = parsing[i].locations[j].find(target, start)) != std::string::npos)
			{
				start = start + target.length(); // avance la taille de target
				while (parsing[i].locations[j][start] == '	' or parsing[i].locations[j][start] == ' ')
					start++; // avance
				end = start;
				while (parsing[i].locations[j][end] != ';' && parsing[i].locations[j][end] != ' ')
					end++; // avance juqu'a la fin de res
				res = parsing[i].locations[j].substr(start, end - start); // prend res
				start = end;
				parsing[i].location[j].path_index = parsing[i].location[j].root + '/' +res;
			}
		}
	}
}

void	find_dir_listing(std::vector<s_parsing> &parsing)
{
	for (int i = 0; i < parsing.size(); i++)
	{
		for (int j = 0; j < parsing[i].location.size(); j++)
		{
			int				start = 0;
			int				end = 0;
			std::string		target = "directory_listing";
			std::string		res;

			while ((start = parsing[i].locations[j].find(target, start)) != std::string::npos)
			{
				start = start + target.length(); // avance la taille de target
				while (parsing[i].locations[j][start] == '	' or parsing[i].locations[j][start] == ' ')
					start++; // avance
				end = start;
				while (parsing[i].locations[j][end] != ';' && parsing[i].locations[j][end] != ' ')
					end++; // avance juqu'a la fin de res
				res = parsing[i].locations[j].substr(start, end - start); // prend res
				parsing[i].location[j].dir_listing = res;
			}
		}
	}
}

void	find_methods(std::vector<s_parsing> &parsing)
{
	for (int i = 0; i < parsing.size(); i++)
	{
		for (int j = 0; j < parsing[i].location.size(); j++)
		{
			int				start = 0;
			int				end = 0;
			std::string		target = "	allow_methods";
			std::string		res;

			while ((start = parsing[i].locations[j].find(target, start)) != std::string::npos)
			{
				start = start + target.length(); // avance la taille de target
				while (parsing[i].locations[j][start] == '	' or parsing[i].locations[j][start] == ' ')
					start++; // avance
				end = start;
				while (parsing[i].locations[j][end] != ';' && parsing[i].locations[j][end] != ' ')
					end++; // avance juqu'a la fin de res
				res = parsing[i].locations[j].substr(start, end - start); // prend res
//				std::cout << res << std::endl;
				parsing[i].location[j].methods = res;
			}
		}
	}
}

void	find_redir(std::vector<s_parsing> &parsing)
{
	for (int i = 0; i < parsing.size(); i++)
	{
		for (int j = 0; j < parsing[i].location.size(); j++)
		{
			int				start = 0;
			int				end = 0;
			std::string		target = "return";
			std::string		key;
			std::string		res;

			while ((start = parsing[i].locations[j].find(target, start)) != std::string::npos)
			{
				start = start + target.length(); // avance la taille de target
				while (parsing[i].locations[j][start] == ' ' or parsing[i].locations[j][start] == '	')
					start++; // avance
				end = start;
				while (parsing[i].locations[j][end] != '	' && parsing[i].locations[j][end] != ' ')
					end++; // avance juqu'a la fin de key
				key = parsing[i].locations[j].substr(start, end - start); // prend key
				start = end;
				while (parsing[i].locations[j][start] == ' ' or parsing[i].locations[j][start] == '	')
					start++;
				end = start;
				while (parsing[i].locations[j][end] != ' ' && parsing[i].locations[j][end] != ';')
					end++;
				res = parsing[i].locations[j].substr(start, end - start);
				parsing[i].location[j].redir[key] = res;
			}
		}
	}
}

void	find_cgi(std::vector<s_parsing> &parsing)
{
	for (int i = 0; i < parsing.size(); i++)
	{
		for (int j = 0; j < parsing[i].location.size(); j++)
		{
			int				start = 0;
			int				end = 0;
			std::string		target = "cgi_info";
			std::string		key;
			std::string		res;

			while ((start = parsing[i].locations[j].find(target, start)) != std::string::npos)
			{
				start = start + target.length(); // avance la taille de target
				while (parsing[i].locations[j][start] == ' ' or parsing[i].locations[j][start] == '	')
					start++; // avance
				end = start;
				while (parsing[i].locations[j][end] != '	' && parsing[i].locations[j][end] != ' ')
					end++; // avance juqu'a la fin de key
				key = parsing[i].locations[j].substr(start, end - start); // prend key
				start = end;
				while (parsing[i].locations[j][start] == ' ' or parsing[i].locations[j][start] == '	')
					start++;
				end = start;
				while (parsing[i].locations[j][end] != ' ' && parsing[i].locations[j][end] != ';')
					end++;
				res = parsing[i].locations[j].substr(start, end - start);
				parsing[i].location[j].cgi[key] = res;
			}
		}
	}
}
*/

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
