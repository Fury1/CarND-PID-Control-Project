# CarND-Controls-PID

Self-Driving Car Engineer Nanodegree Program PID Project

---

## Project Reflection

#### *Describe the effect each of the P, I, D components had in your implementation*

In my implementation of the PID controller the following effects have been recognized:

* P - This portion of the controller formula seemed to affect the quickness/aggressiveness of the steering. When the vehicle was trying to correct its path from the cross track error (CTE) a higher "P" coefficient made the car compensate much harder and faster to the correct location on the track. A higher value here also caused more of an over steer problem. It took some trial and error to find the balance of steering fast enough to make the turns on the track, while keeping over steer to a minimum.

* I - This portion of the PID controller was the most sensitive coefficient. When increased or decreased the vehicle would veer to one side of the track. Additionally, I found this coefficient even at small values of <.001 to be un-useful for the purposes of the simulator. In a real would situation I am aware that compensating for a bias is needed at times, however, given there is no kind of bias or vehicle drift present in the simulator I found it provided more problems then solutions.

* D - In the simulator this coefficient was used to compensate for the over steer that "P" creates. I found that a large value in relation to "P" was needed to keep over steer to a minimum. I also think that it is worth noting that using an excessively large "D" coefficient also created more over steer in the opposite direction. This was observed through some experimentation.

#### *Describe how the final hyperparameters were chosen*

The final hyperparameters for PID were chosen through controlled manual trial and error. To start I figured I would try to see if I could just get the vehicle to steer itself around the track even if it over steered and oscillated. All coefficients were set to 0, and I began incrementing "P" by 0.1 at a time between test laps. After realizing that going to high with "P" made the car steer wildly and crash, I eventually settled on 0.2. This gave a balance of steering quickly enough to make the turns as well as not being overly sensitive and crashing the car. Large oscillations were present while driving straight and around turns, but I could just about navigate the track.

Next, I skipped over "I" because I wanted to correct the oscillations that "P" created when steering. I again began to increment "D" by 0.1 between tests. I found that the over steer did not improve much even after increasing "D" to 1.0. At that point I started increasing "D" by whole numbers to see if I could get it to make any kind of difference. In the end, I found that 6.0 minimized over steer and the oscillations while driving straight, yet allowed me to make the turns quick enough to not run off the track and crash. Values higher then 6.0 started actually create more over steer in the opposite direction. I assumed that the higher values over power the proportional (P) portion of the PID formula.

After adjusting and testing "P" and "D" I was pretty happy with the result. The car could successfully drive the track as specified by the project rubric. Just to see what happened, I did play around with the "I" coefficient and found that it was highly sensitive even at small values of .001. In the simulator there was really no need for it because any kind of drift or bias was not being modeled. Setting "I" beyond 0 was pointless in my opinion, however, I did find it interesting to see how you could make the steering angle favor one side or the other. If the track was totally circular in one direction, it might of been more useful in keeping the car centered, left, or right of the lane.

#### Conclusion

The final hyperparameters were choosen through a simple yet methodic sequence of trial and error. In the end the combination of "P" and "D" parameters were enough to get the vehicle to drive laps around the simulator. I do believe that in the real world a more complicated controller would be needed to drive a car safely down a road. However, the PID controller is a simple and effective means to make a basic vehicle controller quickly and easily.
