const openbr = require('bindings')('openbr');

console.log('ageEstimation:', openbr.ageEstimation("/srv/node/data/a.jpg"));
console.log('genderEstimation:', openbr.genderEstimation("/srv/node/data/a.jpg"));
