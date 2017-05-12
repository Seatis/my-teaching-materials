'use strict';

const test = require('tape');
const extend = require('extend.js');

test('add 2 and 3 is 5', function (t) {
  t.equal(extend.add(2, 3), 5);
  t.end();
});

test('add 4 and 1 is 5', function (t) {
  t.equal(extend.add(4, 1), 5);
  t.end();
});

test('max of three first', function (t) {
  t.equal(extend.maxOfThree(5, 4, 3), 5);
  t.end();
});

test('max of three third', function (t) {
  t.equal(extend.maxOfThree(3, 4, 5), 5);
  t.end();
});

test('median four', function (t) {
  t.equal(extend.median([7, 5, 3, 5]), 5);
  t.end();
});

test('median five', function (t) {
  t.equal(extend.median([1, 2, 3, 4, 5]), 3);
  t.end();
});

test('is vovel a', function (t) {
  t.ok(extend.isVovel('a'), true);
  t.end();
});

test('is vovel b', function (t) {
  t.ok(extend.isVovel('b'), true);
  t.end();
});

test('translate bemutatkozik', function (t) {
  t.equal(extend.translate('bemutatkozik'), 'bevemuvutavatkovozivik');
  t.end();
});

test('translate kirakatbábú', function (t) {
  t.equal(extend.translate('kirakatbábú'), 'kiviravakavatbávábúvú');
  t.end();
});
