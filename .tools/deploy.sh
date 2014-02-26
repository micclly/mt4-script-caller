#!/bin/bash

MYDIR=$(dirname $0)

. $MYDIR/common.sh

rsync -av --files-from=$FILESET $SRC_MQL4DIR/ $MQL4DIR/
