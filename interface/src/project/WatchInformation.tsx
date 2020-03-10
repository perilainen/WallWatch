import React, { Component } from 'react';
import { Typography, List, Link} from '@material-ui/core';
import { SectionContent } from '../components';

class WatchInformation extends Component {

  render() {
    return (
      <SectionContent title='Watch Information' titleGutter>
        <Typography variant="body1" paragraph>
          En liten beskrivning av inställningar du kan och bör göra för klockan
        </Typography>
        <Typography variant="body1" paragraph>
          Du behöver koppla in klockan på ditt wifi, det gör du under 
          <Link href="/wifi/"> Wifi Connection,</Link> där kan du söka upp ditt wifi och ange lösenord
        </Typography>

        <Typography variant="body1" paragraph>
          När du har kopplat in klockan till ditt wifi kan du ansluta till ditt vanliga wifi och fortsätta inställningarna, du kommer åt klockan genom att
          skriva http://wallclock i weäsarebbl
        </Typography>
        <Typography variant="body1" paragraph>
          Under <Link href="/ntp/settings/"> Network time </Link> gör du inställningar för vilken tidszon som ska visas. 
          <Link href="/ntp/status"> Här</Link> kan du se vad klockan är just nu
        </Typography>
        <Typography variant="body1" paragraph>
          <Link href="/project/watch/controller/">Här </Link>ställer du in vilken färg klockan har
        </Typography>
        <Typography variant="body1" paragraph>
          Man kan också ändra vad klockans accespunkt ska heta samt lösenord <Link href="/ap/settings/">här</Link>.
        </Typography>
        <Typography variant="body1" paragraph>
          Om du vill ändra webbadressen till klockan ändrar du klockans Hostname <Link href="/wifi/settings">här</Link>
          </Typography>
      </SectionContent>
    )
  }

}

export default WatchInformation;