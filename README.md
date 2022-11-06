# Analysis-sequential-data

Possible problems present in a data set:

• data values that do not make sense and should not exist (outlier/exceptional values)

• lack of data in certain time intervals, due to temporary gaps (gaps)

• too much oscillation between values (noise)

• the data is unevenly distributed over time (in one second we have 5 recordings, in the next
second 22 records)


# Data Format
D = {x|x = (timestamp, value), timestamp ∈ [0, 300000], value ∈ R}

timestamp- - time represented in milliseconds
Input format:

NumberOfData

timestamp value

timestamp value

...............

timestamp value

# Exception Elimination using static methods
The elimination of exceptions will be done by scrolling through the list of values, using a window
size k = 5 for which the mean and standard deviation will be calculated at each step. The window will be built around a node and node it will be eliminated if it differs too much from the other nodes in the window. First int(k/2) and the last int(k/2) values in the list will be ignored in the elimination process and will remains in the list.

![image](https://user-images.githubusercontent.com/94039813/200200590-d4318e7e-83ca-42a0-b6a0-d76104561968.png)  , values mean

![image](https://user-images.githubusercontent.com/94039813/200200612-dfdf4eef-2498-4b3f-999e-06d5516325b9.png)  , standard deviation

If the value of the current node is notin the interval  ![image](https://user-images.githubusercontent.com/94039813/200200635-089ed736-c098-4511-bbf4-6b3d01ebfd6b.png) , the node will be eliminated.

# Noise elimination using filters
The timestamp of the data remains identical to the initial one. Only the value changes. For each calculated value with one of the filters below, the timestamp will be the one in the center of the sublist used in that calculation.

Median Filter:
The median value is obtained by sorting numbers and taking the position value in the middle. Median filtering works by considering a list of length k = 5 around each node.
For each window, the median value is considered, and a new list is created from these values.

Filter using arithmetic mean:
The algorithm works on 5-length sublists. For every sublist, the arithmetic mean is calculated and the result is added in another list.

# Uniformity of data frequency over time

We will try to move data from high frequency areas to
areas with lower frequency. If the time difference between any two consecutive dates
is in the interval ∈ [0.1, 1] seconds, then the value of the current node will be replaced with the value
average between the previous node and the current node.

![image](https://user-images.githubusercontent.com/94039813/200201062-1e75b2b6-367e-4842-9bf7-d49f190cadc7.png)

# Output format
If the missing intervals are greater than a fixed threshold, then the completion process will be
more complex than a simple average between edges. For each interval we will consider the most
near neighbours on the left and right. For simplicity, we take k = 3 neighbors for each
edge of the current range. Using these values, we approximate the values that should
appear in that interval, using a weighted average of the neighbours. To be able to parameterize
this formula, we also introduce a scaling factor C, which allows us to generate points
anywhere in the interval ∈ [right[k].timestamp, lef t[k].timestamp] .
The closest elements to the edges of the range are towards the end of the right and left lists.

![image](https://user-images.githubusercontent.com/94039813/200201378-859abd0a-72be-48a8-a9ef-d7fc6f754a95.png)

Because we would like the influence of the points to decrease as we move away from the current interval
, we introduce a coefficient that will decrease the influence of the values as we move away
of interval. The i parametermeans the current position of the point, and k represents the number of
points taken into account.

![image](https://user-images.githubusercontent.com/94039813/200201478-0f21bbe5-4e39-4a21-9fe6-cd98fd494918.png)

![image](https://user-images.githubusercontent.com/94039813/200201487-05638dfe-448c-490e-b957-893b9dc323f1.png)

# Statistics
![image](https://user-images.githubusercontent.com/94039813/200201625-3efec645-5f2d-4381-b2f3-213bd968879a.png)  is divided into intervals of length δ. For each interval it will be
counted how many times we have a point in the set of data that is in that interval. Finally,
the intervals sorted by the bottom edge and the number of elements from that interval will be displayed on one line. 



