// Math.floor(mass / 3) - 2
let massArray = [|
  119965,
  69635,
  134375,
  71834,
  124313,
  109114,
  80935,
  146441,
  120287,
  85102,
  148451,
  69703,
  143836,
  75280,
  83963,
  108849,
  133032,
  109359,
  78119,
  104402,
  89156,
  116946,
  132008,
  131627,
  124358,
  56060,
  141515,
  75639,
  146945,
  95026,
  99256,
  57751,
  148607,
  100505,
  65002,
  78485,
  84473,
  112331,
  82177,
  111298,
  131964,
  125753,
  63970,
  77100,
  90922,
  119326,
  51747,
  104086,
  141344,
  54409,
  69642,
  70193,
  109730,
  73782,
  92049,
  90532,
  147093,
  62719,
  79829,
  142640,
  85242,
  128001,
  71403,
  75365,
  90146,
  147194,
  76903,
  68895,
  56817,
  142352,
  77843,
  64082,
  106953,
  115590,
  87224,
  58146,
  134018,
  127111,
  51996,
  134433,
  148768,
  103906,
  52848,
  108577,
  77646,
  95930,
  67333,
  98697,
  55870,
  78927,
  148519,
  68724,
  93076,
  73736,
  140291,
  121184,
  111768,
  71920,
  104822,
  87534,
|];

let requiredFuel = mass => mass / 3 - 2;

let rec calculateFuel = (fuel, current) => {
  let extraFuel = requiredFuel(fuel);

  extraFuel > 0 ? calculateFuel(extraFuel, current + fuel) : current + fuel;
};

let fuel =
  Array.fold_left(
    (acc, mass) => {
      let fuel = requiredFuel(mass);
      Js.log({j|fuel: $fuel|j});
      let extra = calculateFuel(fuel, 0) - fuel;
      Js.log({j|extra: $extra|j});
      let total = extra + fuel;
      Js.log({j|total: $total|j});
      Js.log({j|acc: $acc|j});
      acc + total;
    },
    0,
    massArray,
  );

Js.log(fuel);