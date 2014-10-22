/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

angular.module('app', ['components'])

        .controller('BeerCounter', function ($scope, $locale) {
            $scope.beers = [0, 1, 2, 3, 4, 5, 6];
            if ($locale.id == 'en-us') {
                $scope.beerForms = {
                    0: 'no beers',
                    one: '{} beer',
                    other: '{} beers'
                };
            } else {
                $scope.beerForms = {
                    0: 'žiadne pivo',
                    one: '{} pivo',
                    few: '{} pivá',
                    other: '{} pív'
                };
            }
        });


