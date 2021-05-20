

void Sonic(){
   dist=sr04.Distance();
   if(abs(dist-last_dist)>=threshold){
      last_dist = dist;
      SERIALmessage(100, dist);
   }
}
