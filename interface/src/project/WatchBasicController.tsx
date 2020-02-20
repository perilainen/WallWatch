import React, { Component } from 'react';
import { ValidatorForm } from 'react-material-ui-form-validator';

import { Typography, Slider, Box } from '@material-ui/core';
import SaveIcon from '@material-ui/icons/Save';

import { ENDPOINT_ROOT } from '../api';
import { restController, RestControllerProps, RestFormLoader, RestFormProps, FormActions, FormButton, SectionContent } from '../components';

export const WATCH_SETTINGS_ENDPOINT = ENDPOINT_ROOT + "watchSettings";

interface WatchSettings {
  red: number;
  green: number;
  blue: number;
}

type WatchControllerProps = RestControllerProps<WatchSettings>;

class WatchController extends Component<WatchControllerProps> {

  componentDidMount() {
    this.props.loadData();
  }

  render() {
    return (
      <SectionContent title='Demo Controller' titleGutter>
        <RestFormLoader
          {...this.props}
          render={props => (
            <WatchControllerForm {...props} />
          )}
        />
      </SectionContent>
    )
  }

}

export default restController(WATCH_SETTINGS_ENDPOINT, WatchController);

const valueToPercentage = (value: number) => `${Math.round(value / 255 * 100)}%`;

type WatchControllerFormProps = RestFormProps<WatchSettings>;

function WatchControllerForm(props: WatchControllerFormProps) {
  const { data, saveData, loadData, handleSliderChange } = props;
  return (
    <ValidatorForm onSubmit={saveData}>
      <Typography id="blink-speed-slider">
        Red
      </Typography>
      <Box pt={5}>
        <Slider
          value={data.red}
          valueLabelFormat={valueToPercentage}
          aria-labelledby="blink-speed-slider"
          valueLabelDisplay="on"
          min={0}
          max={255}
          onChange={handleSliderChange('red')}
        />
      </Box>
      <Typography id="blink-speed-slider">
        Red
      </Typography>
      <Box pt={5}>
        <Slider
          value={data.green}
          valueLabelFormat={valueToPercentage}
          aria-labelledby="blink-speed-slider"
          valueLabelDisplay="on"
          min={0}
          max={255}
          onChange={handleSliderChange('green')}
        />
      </Box>
      <Typography id="blink-speed-slider">
        Red
      </Typography>
      <Box pt={5}>
        <Slider
          value={data.blue}
          valueLabelFormat={valueToPercentage}
          aria-labelledby="blink-speed-slider"
          valueLabelDisplay="on"
          min={0}
          max={255}
          onChange={handleSliderChange('blue')}
        />
      </Box>
      <FormActions>
        <FormButton startIcon={<SaveIcon />} variant="contained" color="primary" type="submit">
          Save
        </FormButton>
        <FormButton variant="contained" color="secondary" onClick={loadData}>
          Reset
        </FormButton>
      </FormActions>
    </ValidatorForm>
  );
}


