/*if after executing the instructions for the first time, the robot has back to (0,0) return true;
if after executing the instructions for the first time, the robot does not back to (0,0), check the direction and if dir is not facing north,
return true;
otherwise return false*/
class Solution {
    private class Position
    {
        int row;
        int col;
        public Position()
        {
            row = 0;
            col = 0;
        }
        
        public boolean isOringinal()
        {
            return this.row == 0 && this.col == 0;
        }
        
    }
    
    private void Move(Position p, int direction)
    {
        if(direction == 0)
        {
            p.col++;
        }
        else if(direction == 1)
        {
            p.row++;
        }
        else if(direction == 2)
        {
            p.col--;
        }
        else
        {
            p.row--;
        }
            
    }
    public boolean isRobotBounded(String instructions) 
    {
        //do it as clockwise, 0->north, 1->east, 2->south, 3->west
        Position p = new Position();
       int direction = 0;
        for(char c : instructions.toCharArray())
        {
            switch(c)
            {
                case 'L' :
                    --direction;
                    if(direction < 0)
                    {
                        direction += 4;
                    }
                    break;
                    
                case 'R' :
                    ++direction;
                    direction %= 4;
                    break;
                    
                case 'G' :
                    Move(p, direction);
                    break;
                    
                default : 
                    break;    
            }
        }
        if(p.isOringinal())
        {
            return true;
        }
        
        return direction != 0;
    }
}