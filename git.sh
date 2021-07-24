#!/bin/bash
git add --all .
git commit -m "update"
git remote add origin https://github.com/Vinnichenko-Ivan/SplineEditor.git
git push -u origin master
echo Vinnichenko-Ivan