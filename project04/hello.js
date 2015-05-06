console.log('node is installed');

var arDrone = require('ar-drone');
var client = arDrone.createClient();

client.takeoff();

// client
//   .after(5000, function() {
//     this.clockwise(0.5);
//   })
//   .after(3000, function() {
//     this.animate('flipLeft', 15);
//   })
//    .after(3000, function() {
//     this.animate('doublePhiThetaMixed', 15);
//   })
//   .after(5000, function() {
//     this.stop();
//     this.land();
//   });

// client
//   .after(1000, function() {
//      this.stop();
//    })  //Hover
//   .after(5000, function() {
//     this.front(0.3);
//   })
//   .after(4000, function() {
//     this.stop();
//   })
//   .after(5000, function() {
//     this.back(0.3);
//   })
//   .after(4000, function() {
//     this.animate('flipLeft', 15);
//   })
//   .after(4000, function() {
//     this.stop();
//     this.land();
//   });

// client
//   .after(1000, function() {
//      this.stop();
//    })  //Hover
//   .after(5000, function() {
//     this.up(0.5);
//   })
//   .after(5000, function() {
//     this.front(0.3);
//   })
//   .after(5000, function() {
//     this.counterClockwise(0.5);
//   })
//    .after(3000, function() {
//     this.front(0.3);
//   })
//    .after(5000, function() {
//     this.counterClockwise(0.5);
//   })
//    .after(3000, function() {
//     this.front(0.3);
//   })
//    .after(5000, function() {
//     this.counterClockwise(0.5);
//   })
//   .after(3000, function() {
//     this.stop();
//     this.land();
//   });

// client
//   .after(1000, function() {
//      this.stop();
//   })  //Hover
//   .after(5000, function() {
//     this.counterClockwise(0.5);
//   })
//   .after(1750, function() {
//        this.stop();
//   })  //Hover
//   .after(3000, function() {
//     this.front(0.3);
//   })
//   .after(5000, function() {
//      this.stop();
//   })  //Hover
//   .after(3000, function() {
//     this.counterClockwise(0.5);
//   })
//   .after(1750, function() {
//        this.stop();
//   })  //Hover
//   .after(3000, function() {
//     this.front(0.3);
//   })
//   .after(5000, function() {
//      this.stop();
//   })  //Hover
//   .after(3000, function() {
//     this.counterClockwise(0.5);
//   })
//   .after(1750, function() {
//        this.stop();
//   })  //Hover
//     .after(3000, function() {
//     this.up(0.5);
//   })
//   .after(3000, function() {
//     this.front(0.3);
//   })
//   .after(5000, function() {
//        this.stop();
//   })  //Hover
//   .after(3000, function() {
//     this.counterClockwise(0.5);
//   })
//   .after(1750, function() {
//        this.stop();
//   })  //Hover
//   .after(3000, function() {
//     this.front(0.3);
//   })
//   .after(3000, function() {
//      this.stop(); // to account for wind
//   })  //Hover
//   .after(5000, function() {
//     this.stop();
//     this.land();
//   });

client
   .after(5000, function() {
    this.animate('turnaround', 30);
  })
  .after(10000, function() {
    this.stop();
    this.land();
  });