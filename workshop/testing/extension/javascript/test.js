'use strict';

const test = require('tape');
const extend = require('./extend.js');

test('addNumbers: add 2 and 3 is 5', function (t) {
  t.equal(extend.addNumbers(2, 3), 5);
  t.end();
});

test('addNumbers: add 4 and 2 is 6', function (t) {
  t.equal(extend.addNumbers(4, 2), 6);
  t.end();
});

test('addNumbers: add string throws error', function (t) {
  t.throws(function() { extend.addNumbers(4, 'string') }, 'Invalid value');
  t.end();
});

test('maxOfThree: max of three first', function (t) {
  t.equal(extend.maxOfThree(5, 4, 3), 5);
  t.end();
});

test('maxOfThree: max of three third', function (t) {
  t.equal(extend.maxOfThree(3, 4, 5), 5);
  t.end();
});

test('maxOfThree: add string throws error', function (t) {
  t.throws(function() { extend.maxOfThree('string', 'string', 'string')}, 'Invalid value');
  t.end();
});

test('median: median four', function (t) {
  t.equal(extend.median([7, 5, 3, 5]), 5);
  t.end();
});

test('median: median five', function (t) {
  t.equal(extend.median([1, 2, 3, 4, 5]), 3);
  t.end();
});

test('median: add string returns error message', function (t) {
  t.equal(extend.median([1, 2, 3, 4, 'string']), 'Invalid value');
  t.end();
});

test('isVovel: is vovel a', function (t) {
  t.ok(extend.isVovel('a'), true);
  t.end();
});

test('isVovel: is vovel b', function (t) {
  t.ok(extend.isVovel('b'), true);
  t.end();
});

test('isVovel: empty string returns error message', function (t) {
  t.equal(extend.isVovel(''), 'Please, give me one character');
  t.end();
});

test('isVovel: more the one character returns error message', function (t) {
  t.equal(extend.isVovel('life is better with bacon'), 'Please, give me one character');
  t.end();
});

test('translate bemutatkozik', function (t) {
  t.equal(extend.translate('bemutatkozik'), 'bevemuvutavatkovozivik');
  t.end();
});

test('translate number returns error message', function (t) {
  t.equal(extend.translate(12345), 'Invalid value');
  t.end();
});
