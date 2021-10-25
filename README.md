***************************************************************************                                                                    
  This program is free software; you can redistribute it and/or modify  
  it under the terms of the GNU General Public License as published by  
  the Free Software Foundation; either version 2 of the License, or     
  (at your option) any later version.                                   
 
  This program is distributed in the hope that it will be useful,       
  but WITHOUT ANY WARRANTY; without even the implied warranty of        
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         
  GNU General Public License for more details.                          
 
  You should have received a copy of the GNU General Public License     
  along with this program; if not, write to the                         
  Free Software Foundation, Inc.,                                       
  59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             
***************************************************************************
This is my first programming project. Don't expect too much from this code.
***************************************************************************

 1.  NAME
     Game Of Life

 2.  DESCRIPTION

 3.  VERSIONS
       Original:
        1.0 Game of Life 1.4.2020

       Version history:

        1.0 Game of Life

        2.0 Game of Life: The Europe 20.4.2020

        2.1 Game of Life: The Europe, Attack of Russia 25.4.2020

***********************************************************

EUROPEAN RULES (WHITE)
-----------------------------------------------------------
***********************************************************
-*Grass
  
  Immunities: 
  
    neighbours = action
  
  2 = do nothing
  3 = change value to 1 (new population)
  less than 2 = change value to 0 (Lonliness)
  more than 3 = change value to 0 (Overpopulation)

***********************************************************
-*Mountain
  
  Immunities: Immune to lonliness
  
   neighbours = action
  
  less than 3 = do nothing
  3 or 4 = change value to 1 (new population)
  more than 4 = change value to 0 (Overpopulation)

***********************************************************
-*Bunker

  Immunities: Immune to overpopulation
  
   neighbours = action
  
  less than 1 = change value to 0 (Lonliness)
  1-2, more than 6 = do nothing
  from 3 to 5 = change value to 1 (new population)

***********************************************************


RUSSIAN RULES (RED)
-----------------------------------------------------------
***********************************************************
*Grass
  
  Immunities: 
  
   neighbours = action

  less than 2 = change value to 0 (Lonliness)  
  2,4 or 5 = do nothing
  3 = change value to 1 (new population)
  more than 5 = change value to 0 (Overpopulation)

***********************************************************
*Mountain
  
  Immunities: Immune to lonliness
  
   neighbours = action
  
  1 = do nothing
  2-4 = change value to 1 (new population)
  more than 4 = change value to 0 (Overpopulation)

***********************************************************
  *Bunker

  Immunities: Immune to overpopulation and lonliness
  
   neighbours = action
  
  more than 2 = New population

***********************************************************
