	int maxMagicalGirls(vector <string> love) 
	{
		
		for(int k = 0; k < love.size(); k++)
			for(int i = 0; i < love.size(); i++)
				for(int j = 0; j < love.size(); j++)
					if(love[i][k] == 'Y' && love[k][j] == 'Y')
						love[i][j] = 'Y';
		
                for(int x = 0; x < love.size(); x++)
                    cout << love[x] << endl;
		int val = 1 << love.size();
		int maxi = 0;
		
		for(int mask = 0; mask < val; mask++)
		{
			vector<bool> prot(love.size(), false);
			vector<int> done;
			
			int tot = 0;
			for(int x = 0; x < love.size(); x++)
			{
				if((1 << x) & mask)
				{
                    done.push_back(x);
					for(int a = 0; a < love.size(); a++)
					{
                                            
						if(love[x][a] == 'Y')
						{
							prot[a] = true;
						}
					}
				}
			}
			for(int q = 0; q < done.size(); q++)
				if(!prot[done[q]])
					tot++;
			
			maxi = max(tot, maxi);
		}
		
		return maxi;
	}