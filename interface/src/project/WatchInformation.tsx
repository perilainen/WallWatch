import React, { Component } from 'react';
import { Typography } from '@material-ui/core';
import { SectionContent } from '../components';

class WatchInformation extends Component {

  render() {
    return (
      <SectionContent title='Watch Information' titleGutter>
        <Typography variant="body1" paragraph>
          Small description
        </Typography>
        
      </SectionContent>
    )
  }

}

export default WatchInformation;